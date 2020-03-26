#%% (1) review

import time
import random

class Human :
    def __init__(self, name, age, gender, money=0) :
        self.name = name
        self.age = age
        self.gender = gender
        self.money = money
    
    def show(self) :
        print("이름 : "+self.name)
        print("나이 : "+str(self.age)+"살")
        print("성별 : "+self.gender)
        print("잔고 : "+str(self.money)+"원")
        
    


class Client :
    def __init__(self, name, idea, cnt=0) :
        self.name = name
        self.idea = idea
        self.cnt = cnt
        
    def show(self) :
        print("<의뢰인의 정보>")
        print()
        print("이름 : "+self.name)
        print("특허 내용 : "+self.idea)


#1. fee(특허출품시 수수료)
#2. 랜덤한 특허를 의뢰받고 50%확률로 출원성공(초기)
#   특허출원시 받을 원금은 100만원부터 1억원까지 있다.
#   초기 수수료는 10%이다.
#   3번 연속 성공시 성공확률 10%증가, 수수료 10%증가
#   2번 연속 실패시 성공확률 3%감소, 수수료 5%감소
#3. 출원시 걸리는 시간은 3초
class Patent(Human) :
    
    probTemp = [0]*100
    prob = 50
    fee = 10
    price = 0 
    
    winCnt = 0
    loseCnt =0
    
    def __init__(self, name, age, gender, ID, pw, money=0) :
        super().__init__(name, age, gender, money)
        self.ID = ID
        self.pw = pw
    
    
    def show(self) :
        print("<변리사님의 정보>")
        print()
        print("이름 : "+self.name)
        print("나이 : "+str(self.age)+"살")
        print("성별 : "+self.gender)
        print("잔고 : "+str(self.money)+"원")
    
   
    
    def submit(self, client) :
        
        for i in range(self.prob) :
            self.probTemp[i] = 1
        
        
        income = random.randrange(1000000,100000001)
        
        prob_rand = random.randrange(0,len(self.probTemp))
        
        client.cnt += 1
        print(str(client.cnt)+"번째 고객")
        print("의뢰인 : "+client.name)
        print("특허명 : "+client.idea)
        print("특허 출원 중",end='')
        for i in range(3) :
            print(".",end='')
            time.sleep(1)
        
        #출원 성공
        if self.probTemp[prob_rand] == 1 :
            
            self.loseCnt = 0
            self.winCnt += 1
            
            if client.cnt % 5 == 0:
                self.price = income*((self.fee //2) / 100)
                self.money += income*((self.fee //2) / 100)
            else :
                self.price = income*(self.fee / 100)
                self.money += income*(self.fee / 100)
                
            print(client.name+"님의 "+client.idea+" 출원 성공!!")
            print("수입 : "+str(self.price))
            print("현재 잔고 : "+str(self.money)+"원")
            
            #3번 연속 출원 성공 시 성공확률 10%, 수수료 10% 증가
            if self.winCnt % 3 == 0:
                self.prob += 10
                self.fee += 10
            
            
            
        #출원 실패    
        else :
            self.loseCnt += 1
            self.winCnt = 0
            client.cnt -= 1
            print(client.name+"님의 "+client.idea+" 출원 실패...")
            
            #2번 연속 출원 실패 시 성공확률 3%, 수수료 5% 감소
            if self.loseCnt % 2 == 0 :
                self.prob -= 3
                self.fee -= 5
                
                

        
        
                
                
                
#변리사의 아이디와 비밀번호를 저장해줄 저장공간
#key값은 아이디로 받고 value값은 비밀번호로 받는다.
patentID_Dict = {}
patentList = []
clientList = []
currentUser = None


#변리사를 등록하는 메소드
#아이디, 비밀번호, 이름, 나이, 성별을 입력받고 객체를 생성해준다.
def registerP() :
    print("<변리사님을 등록합니다.>")
    
    
    ID = input("ID를 입력해주세요\n>>")
    if ID in patentID_Dict :
        print("등록실패! : 중복된 아이디")
    else :
        pw = input("비밀번호를 입력해주세요\n>>")    
        name = input("이름을 입력해주세요\n>>")
        age = int(input("나이를 입력해주세요\n>>"))
        gender = input("성별을 입력해주세요\n>>")
        patentID_Dict[ID] = pw
        patentList.append(Patent(name, age, gender, ID, pw))
        print("등록 완료!!")
    
#의뢰인을 등록하는 메소드
#이름과 특허 내용을 입력받고 객체를 생성해준다.
def registerC() :
    print("<의뢰인을 등록합니다.>")
    name = input("이름을 입력해주세요\n>>")
    idea = input("특허내용을 입력해주세요\n>>")
    
    clientList.append(Client(name, idea))
    
def checkID(ID, pw) :
    check = False
    if ID in patentID_Dict :
        if patentID_Dict[ID] == pw :
            check = True
            print("로그인 성공!!")
            print(patentList[list(patentID_Dict.keys()).index(ID)].name+"님 환영합니다.")
        else :
            print("비밀번호 오류!!")
    else :
        print("존재하지 않는 아이디입니다.")
    return check
    


#메인화면


while True :
    msg = "▒▒특허 관리 프로그램▒▒\n1.변리사 페이지\n2.의뢰인 페이지\n3.나가기"
    patentMsg = "1.변리사 등록\n2.변리사 정보\n3.출원하기"
    clientMsg = "1.의뢰인 등록\n2.의뢰인 정보"
    userMsg = "<메뉴를 선택해주세요>\n\n1.현재 잔고 확인\n2.출원 성공률 확인\n3.수수료 확인\n4.출원하기\n5.로그아웃\n>>"
    choiceMsg = "번호를 입력해주세요>>>"
    errMsg = "다시 입력해주세요"
    print(msg)
    
    choice = int(input(choiceMsg))
    #변리사 페이지
    if choice == 1 :
        print(patentMsg)
        choice = int(input(choiceMsg))
        #변리사 등록
        if choice == 1:
            registerP()
        #변리사 정보
        elif choice == 2:
            print("어떤 변리사의 정보를 보고싶으십니까?")
            for i in range(len(patentList)) :
                print((i+1),". ",patentList[i].name)
            choice = int(input(choiceMsg))
            patentList[choice-1].show()
        #출원하기
        #어떤 변리사가 출원을 해야할 지 결정해야 한다. 
        #출원 과정에 해당 변리사는 아이디와 비밀번호를 입력하여야 한다.
        elif choice == 3:
           ID = input("아이디를 입력해주세요\n>>")
           pw = input("비밀번호를 입력해주세요\n>>")
           if checkID(ID, pw) :
               currentUser = patentList[list(patentID_Dict.keys()).index(ID)]
               while True :
                   
                   choice = int(input(userMsg))
                   if choice == 1:
                       print("현재 잔고 : "+str(currentUser.money)+"원")
                   elif choice == 2:
                       print("출원 성공률 : "+str(currentUser.prob)+"%")
                   elif choice == 3:
                       print("수수료 : "+str(currentUser.fee)+"%")
                   elif choice == 4:
                       if len(clientList) == 0 :
                           print("의뢰인이 존재하지 않습니다.")
                    
                       else :
                           for i in range(len(clientList)) :
                               print(str(i+1)+". "+clientList[i].name+" : "+clientList[i].idea)
                           choice = int(input("어떤 특허를 출원하시겠습니까?"))
                           currentUser.submit(clientList[choice-1])
                   elif choice == 5:
                       break
                   else :
                       print(errMsg)
                       
                   
              
        else :
            print(errMsg)
            
            
            
            
    #의뢰인 페이지
    elif choice == 2:
        print(clientMsg)
        choice = int(input(choiceMsg))
        #의뢰인 등록
        if choice == 1:
            registerC()
        #의뢰인 정보
        elif choice == 2:
            print("어떤 의뢰인의 정보를 보고싶으십니까?")
            for i in range(len(clientList)) :
                print((i+1),". ",clientList[i].name)
            choice = int(input(choiceMsg))
            clientList[choice-1].show()
        else :
            print(errMsg)
    elif choice == 3:
        print("프로그램을 종료합니다.")
        break
    else :
        print(errMsg)
    
    
        
        
        
        
        
    
    
    
    
