#%% inheritance test2
class Car:
    def __init__(self, brand, color, price):
        self.brand = brand
        self.color = color
        self.price = price
        
    def engineStart(self):
        print(self.brand + " 열쇠로 시동 킴")

    def engineStop(self):
        print(self.brand + " 열쇠로 시동 끔")
        
class SuperCar(Car):

    def __init__(self, brand, color, price, mode):
        super().__init__(brand, color, price)
        self.mode = mode
    
    #Overriding
    def engineStart(self):
        print(self.brand + "음성으로 시동 킴")
        
    #Overriding
    def engineStop(self):
        print(self.brand + "음성으로 시동 끔")

    def openRoof(self):
        print("지붕 열림")
    
    def closeRoof(self):
        print("지붕 닫힘")

ferrari = SuperCar("Ferrari", "Red", 35000, "Sport")

ferrari.engineStart()
#%% inheritance task
#Human 부모클래스
#1.이름, 나이, 성별, 통장
import random
import time

class Human:
    def __init__(self, name, age, gender, money = 0):
        self.name = name
        self.age = age
        self.gender = gender
        self.money = money
    
    def introduce(self):
        print("이름 : " + self.name)
        print("나이 : " + str(self.age) + "살")
        print("성별 : " + self.gender)
        print("잔고 : " + str(self.money) + "원")
        
#변리사가 의뢰받을 의뢰인 클래스
#의뢰인이 여러명 있기 때문에 클래스로 선언하여 관리한다.
class Owner:
    def __init__(self, name, idea, cnt = 0):
        self.name = name
        self.idea = idea
        #의뢰 횟수
        self.cnt = cnt
    #의뢰가 5번째인지 확인하는 메소드
    #만약 5번째라면 check를 true로 바꿔준다.
    def checkCnt(self):
        check = False
        if self.cnt % 5 == 0:
            check = True
        return check

#(변리사)Patent 자식 클래스
class Patent(Human):
    #기본 수수료 10%
    
    #연속 성공 횟수
    winCnt = 0
    
    #연속 실패 횟수
    loseCnt = 0
    
    #성공할 확률을 저장
    temp = [0] * 100
    
    #50% 확률
    rating = 50
    
    def __init__(self, name, age, gender, money = 0, fee = 0.1):
        super().__init__(name, age, gender, money)
        self.fee = fee
        
    def submit(self, ownerList):
        #이전 확률과 겹치지 않도록 매번 초기화
        self.temp = [0]*100
        #변리사의 성공 확률만큼 반복하여 차례로 1을 넣는다.
        #초기값은 50이므로 1이 100개중에 50개 있고
        #랜덤한 인덱스에서 1이 나오면 50% 확률이라고 
        #볼 수 있다.
        for i in range(self.rating):
            self.temp[i] = 1
            
        #여러 의뢰인 중 랜덤한 의뢰인의 의뢰를 받기 위함.
        owner_rand = random.randrange(0, len(ownerList))
        
        #랜덤한 방에 있는 의뢰인을 owner 객체에 담는다.
        owner = ownerList[owner_rand]
        
        #의뢰인의 의뢰횟수를 1 증가시킨다.
        #5번 째 의뢰시에는 수수료를 반값 할인해주기 위해
        owner.cnt += 1
        print(str(owner.cnt) + "번째 방문 고객")
        
        #출원 성공 시 랜덤한 수익 발생
        income = random.randrange(1000000, 100000001)
        
        #확률(rand)에서 랜덤한 인덱스의 값을 가져오기 위해
        rand = random.randrange(0, len(self.temp))
        
        #출원 시 걸리는 시간은 3초이다.
        print(owner.name + "의 " + owner.idea + "출원 중", end = '')
        
        for i in range(3):
            print(".", end = '')
            time.sleep(0.1)
        #위에서 줄바꿈이 없기 때문에 끝나고 줄바꿈한다.    
        print()
        #50%확률
        if self.temp[rand] == 1:
            #성공
            print(owner.name + "의 " + owner.idea + "출원 성공!!")
            if owner.checkCnt():    
                #5번 이용할 때마다 그 고객은
                #수수료 50% 절감
                self.money += income * (self.fee / 2)
            else:
                self.money += income * self.fee
            
            print("현재 잔고 : " + str(self.money) + "원")
           #성공 시 연속 실패 횟수 초기화
            self.loseCnt = 0
            #성공 시 연속 성공 횟수 1 증가
            self.winCnt += 1
            
            #3연속 성공 시 확률 10%증가
            if self.winCnt % 3 == 0:
                #10%증가
                self.rating += 10
                self.fee *= 1.5
        else:
            #실패
            if owner.checkCnt():
                print("들어옴")
                #5번째 방문에는 할인을 받아야 하는데
                #실패 시 혜택을 받을 수 없으므로
                #4번째 방문으로 친다.
                #따라서 다음에 혜택을 주기위해
                #방문횟수를 1 감소시켜준다.
                owner.cnt -= 1
            print(owner.name + "의 " + owner.idea + "출원 실패...")
            #실패 시 연속 성공 횟수 초기화
            self.winCnt = 0
            #실패 시 연속 실패 횟수 1 증가
            self.loseCnt += 1
                
            #2회 연속 실패 시 성공확률 2% 감소
            if self.loseCnt % 2 == 0:
                #2%감소
                self.rating -= 3
                self.fee *= 0.5
            
#1. fee(특허출품시 수수료)
#2. 랜덤한 의뢰인의 특허를 의뢰받고 50%확률로 출원성공
#   특허출원시 받을 원금은 백만원부터 1억원까지 있다.
#   3번 연속 성공시 성공확률 10%증가, 수수료 50%증가
#   2번 연속 실패시 성공확률 3%감소, 수수료 50%감소
#3. 출원시 걸리는 시간은 3초

#ownerList = [Owner("김철수", "코로나 바이러스 마스크 특허"), Owner("강감찬", "칠판 자동으로 지워주는 로보트 특허"), Owner("이순신", "엔진 없이 가는 배 특허")]
ownerList = [Owner("김철수", "코로나 바이러스 마스크 특허")]
han = Patent("한동석", 20, "남자")
while True:
    choice = int(input("1.특허 출원\n2.내 정보\n3.나가기\n"))

    if choice == 1:
        han.submit(ownerList)
    elif choice == 2:
        han.introduce()
    elif choice == 3:
        break









