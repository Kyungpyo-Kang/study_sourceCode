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
        print("이름 : " + name)
        print("나이 : " + str(age) + "살")
        print("성별 : " + gender)
        print("잔고 : " + str(money) + "원")

class Owner:
    def __init__(self, name, idea, cnt = 0):
        self.name = name
        self.idea = idea
        self.cnt = cnt
    
    def checkCnt(self):
        check = False
        if self.cnt % 5 == 0:
            True
        return check

#(변리사)Patent 자식 클래스
class Patent(Human):
    #기본 수수료 10%
    winCnt = 0
    loseCnt = 0
    temp = [0] * 100
    rating = 50
    
    def __init__(self, name, age, gender, money = 0, fee = 0.1):
        super().__init__(name, age, gender, money)
        self.fee = fee
        
    def submit(self, ownerList):
        for i in range(self.rating):
            self.temp[i] = 1
        owner_rand = random.randrange(0, len(ownerList))
        owner = ownerList[owner_rand]
        owner.cnt += 1
        
        
        income = random.randrange(1000000, 100000001)
        rand = random.randrange(0, len(self.temp))
        
        print(owner.name + "의 " + owner.idea + "출원 중", end = '')
        for i in range(3):
            print(".", end = '')
            time.sleep(1)
            
        print()
        #50%확률
        if self.temp[rand] == 1:
            #성공
            print(owner.name + "의 " + owner.idea + "출원 성공!!")
            if owner.checkCnt():    
                #5번 이용할 때마다 그 고객은
                #수수료 50% 절감
                self.money += income * (self.fee // 2)
            else:
                self.money += income * self.fee
            
            print("현재 잔고 : " + str(self.money) + "원")
            self.loseCnt = 0
            self.winCnt += 1

            if self.winCnt % 3 == 0:
                #10%증가
                self.rating += 10
        else:
            #실패
            if owner.checkCnt():
                owner.cnt -= 1
            print(owner.name + "의 " + owner.idea + "출원 실패...")
            self.winCnt = 0
            self.loseCnt += 1

            if self.loseCnt % 2 == 0:
                #3%감소
                self.rating -= 3
            
#1. fee(특허출품시 수수료)
#2. 랜덤한 특허를 의뢰받고 50%확률로 출원성공
#   특허출원시 받을 원금은 만원부터 100만원까지 있다.
#   3번 연속 성공시 성공확률 10%증가, 수수료 50%증가
#   2번 연속 실패시 성공확률 3%감소, 수수료 50%감소
#3. 출원시 걸리는 시간은 3초

ownerList = [Owner("김철수", "코로나 바이러스 마스크 특허"), Owner("강감찬", "칠판 자동으로 지워주는 로보트 특허"), Owner("이순신", "엔진 없이 가는 배 특허")]
han = Patent("한동석", 20, "남자")
while True:
    choice = int(input("1.특허 출원\n2.내 정보\n3.나가기\n"))

    if choice == 1:
        han.submit(ownerList)
    elif choice == 2:
        han.introduce()
    elif choice == 3:
        break










