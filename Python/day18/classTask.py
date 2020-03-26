#%%
#직업 만들기
#클래스, 상속, 리스트 혹은 딕셔너리, 수익구조, 계급구조
import random as r
import time


class Developer :
    
    rankMoneyDict = {}
    rankList = ["초급","중급","고급"]
    moneyList = [3000,5000,8000]
    probList = [0]*100
    for i in range (len(rankList)) :
        rankMoneyDict[rankList[i]] = moneyList[i]
    
    
    
    def __init__(name, area, money=3000, rank="초급",successCtn=0, failCtn=0, prob = 50) :
        self.name = name
        self.area = area
        self.money = money
        self.rank = rank
        self.successCtn = successCtn
        self.failCtn = failCtn
        self.prob = prob
        
        
        
    def work(self) :
        for i in range(self.prob) :
        probList[i] = 1
        
        rand = r.randrange(len(self.probList))
        print("개발중",end='')
        for i in range(3):
            print(".", end='')
            time.sleep(1)
        print()

        if self.probList[rand] == 1:
            self.successCtn += 1
            self.failCtn = 0
            print("개발 성공!!!")
        else :
            self.successCtn =0
            self.failCtn +=1
            print("개발 실패ㅠㅠ")
            
        self.changeMoney()
        self.changeRank()
        
    
        
    def show(self) :
        print("<개발자님의 정보입니다>")
        print("이름 : "+ self.name)
        print("분야 : "+self.area)
        print("연봉 : "+str(self.money)+"만원")
        print("등급 : "+self.rank+"개발자")
        
    def changeMoney(self) :
        for i in self.rankMoneyDict.keys :
            if self.rank in self.rankMoneyDict :
                self.money = self.rankMoneyDict[self.rank]
        
    def changeRank(self) :
        
        if  self.successCtn != 0 and  self.successCtn%5 == 0 :
            self.rank = self.rankList[self.rankList.index(self.rank)+1]
            
        elif self.failCtn != 0 and self.failCtn%3 == 0 :
            if self.rankList.index(self.rank) == 0 :
                pass
            else :
                self.rank = self.rankList[self.rankList.index(self.rank)-1]
        
    def changeProb(self) :
        if self.successCtn != 0 and  self.successCtn%3 == 0 :
            if self.prob == 100 :
                pass
            else :
                self.prob += 10
        
        elif self.failCtn != 0 and self.failCtn%3 == 0 :
            if self.prob == 10 :
                print("해고당했습니다.")
            else :
                self.prob -= 10
        
        
    def changeArea(self) :
        newArea = input("변경하실 분야를 입력해주세요\n>>")
        while True :
            choice = input("정말로 변경하시겠습니까?__y/n\n>>")
            if choice == 'y' :
                temp = self.area
                self.area = newArea
                print("변경 성공!!")
                print("변경 전 : "+temp)
                print("변경 후 : "+self.area)
                break
            elif chocie == 'n' :
                print("변경이 취소되었습니다.")
                break
            else :
                print(errMsg)
        
    
    
developerList = []   

    
    
def registerD() :
    
    print("개발자님을 등록합니다.>")
    name = input("이름을 입력해주세요\n>>")
    area = input("분야를 입력해주세요\n>>")
    developerList.append(Developer(name, area))
    print("등록 완료!!")
    
  
while True :
    errMsg = "잘못 입력하셨습니다."
    titleMsg = "▒▒개발자 관리 프로그램▒▒\n1.개발자 등록\n2.개발자 정보\n3.일하기\n4.나가기\n>>"  
    choiceMsg = "번호를 입력해주세요>>>"
    
    choice = int(input(titleMsg))
    
    if choice == 1 :
        registerD()
    elif choice == 2 :
        print("어떤 개발자의 정보를 보시겠습니까?")
        for i in range(len(developerList)) :
                print((i+1),". ",developerList[i].name)
        choice = int(input(choiceMsg))
        developerList[choice-1].show()
    elif chocie == 3:
        print("어떤 개발자가 일을 하게 하시겠습니까??")
        for i in range(len(developerList)) :
                print((i+1),". ",developerList[i].name)
        choice = int(input(choiceMsg))
        developerList[choice-1].work()
    elif choice == 4 :
        break
    else :
        print(errMsg)
            
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    