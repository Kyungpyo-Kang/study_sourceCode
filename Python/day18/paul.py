#%% Job Game

import random
import time

#회원가입을 통해 여러명의 회원들에 대한 객체가 생성될 수 있으므로, 클래스를 생성해준다.
class User :
    
    
    def __init__(self, name="", age=0, gender="", userId="", userPw="") :
        self.name = name
        self.age = age
        self.gender =gender
        self.userId = userId
        self.userPw = userPw
    
    #외부에서 아이디를 전달받고 중복확인을 해주는 메소드이다.    
    def checkDup(self, userId) :
        isDup = False
        
        if userId in userIdPwDict.keys() :
            print("가입 불가 : 아이디 중복")
            isDup = True
        
        return isDup
    
    #회원가입 메소드    
    def join(self) :
        print("\n<회원가입>")
        name = input("이름을 입력해주세요\n>>")
        age = int(input("나이를 입력해주세요\n>>"))
        gender = input("성별을 입력해주세요\n>>")
        userId = input("id를 입력해주세요\n>>")
        
        #아이디 중복확인을 해줘야 하기 때문에
        #이름, 나이, 성별, id까지만 먼저 입력받는다.
        
        #checkDup메소드의 리턴값이 true가 아닐 때 아래 문장을 실행한다.
        if name != "" :
            if not self.checkDup(userId) :
                userPw = input("비밀번호를 입력해주세요\n>>")
                if userPw != "" : 
                    #비밀번호까지 입력받았으면 아이디와 비밀번호를 mapping해준다.
                    userIdPwDict[userId] = userPw
                    #추가적으로 key값은 입력받은 id로, value는 객체로 받아준다. 
                    userDict[userId] = User(name, age, gender, userId, userPw)
                    print("\n회원가입 성공!!")
                    print(name+"님 환영합니다.")
                else :
                    print("비밀번호를 입력해주세요.")
        else :
            print("아이디를 입력해주세요.")
        
    #로그인 메소드
    #외부에서 아이디와 비밀번호를 받고 그 아이디(key값)의 value인 비밀번호가 맞다면, true를 리턴한다.    
    def login(self, userId, userPw) :
        isLogin = False
        
        if userId in userIdPwDict.keys() :
            if userIdPwDict[userId] == userPw :
                print("\n로그인 성공!!")
                print(self.name+"님 안녕하세요ㅎㅎ")
                isLogin = True
            else :
                print("로그인 실패 : 비밀번호 오류")
        else :
            print("로그인 실패 : 존재하지 않는 아이디")
        
        return isLogin
        
    
    #유저의 정보를 보여주는 메소드
    def showUser(self) :
        print()
        print(layout)
        print("<"+self.name+"님의 정보>")
        print("이름 : "+self.name)
        print("나이 : "+str(self.age))
        print("성별 : "+self.gender)
        print("아이디 : "+self.userId)
        print("비밀번호 : "+self.userPw)
        print(layout)
    
    #유저의 정보를 바꿔주는 메소드    
    def updateUser(self) :
        titleList = "이름,나이,성별,아이디,비밀번호".split(",")
        print(layout)
        for i in range(len(titleList)) :
            print(str(i+1)+". "+titleList[i])
        print(layout)    
        choice = int(input("무엇을 수정하시겠습니까?\n>>>"))
            
        if choice == 1:
            temp = self.name
            newName = input("새로운 이름 입력 : ")
            if self.name == newName :
                print("수정 실패 :기존 정보와 같습니다.")
            else :
                self.name = newName
                print("<수정 성공>")
                print("변경 전 : "+temp)
                print("변경 후 :"+self.name)
            
        elif choice == 2:
            temp = self.age
            newAge = int(input("새로운 나이 입력 : "))
            if self.age == newAge :
                print("수정 실패 :기존 정보와 같습니다.")
            else :
                self.age = newAge
                print("<수정 성공>")
                print("변경 전 : "+str(temp))
                print("변경 후 :"+str(self.age))
        elif choice == 3:
            temp = self.gender
            newGender = input("새로운 성별 입력 : ")
            if self.gender == newGender :
                print("수정 실패 :기존 정보와 같습니다.")
            else :
                self.gender = newGender
                print("<수정 성공>")
                print("변경 전 : "+temp)
                print("변경 후 :"+self.gender)
            
        #아이디의 경우 중복이 발생할 수 있기 때문에 추가적으로 checkDup메소드를 통해 중복확인을 해준다.
        elif choice == 4:
            temp = self.userId
            newUserId = input("새로운 아이디 입력 : ")
            if self.userId == newUserId :
                print("수정 실패 :기존 정보와 같습니다.")
            else :
                if not self.checkDup(newUserId) :
                    self.userId = newUserId
                    print("<수정 성공>")
                    print("변경 전 : "+temp)
                    print("변경 후 :"+self.userId)
                
        elif choice == 5:
            temp = self.userPw
            newUserPw = input("새로운 비밀번호 입력 : ")
            if self.userPw == newUserPw :
                print("수정 실패 :기존 정보와 같습니다.")
            else :
                self.userPw = newUserPw
                print("<수정 성공>")
                print("변경 전 : "+temp)
                print("변경 후 :"+self.userPw)
            
        else :
            print(errMsg)
            
    
    #게임 실행 메소드
    def gameStart(self) :
        
        while True : 
            choice = int(input(gameMsg))
            if choice == 1:
                if self.userId in userCharDict :
                    print("주의 : 이전의 기록들이 모두 사라질 수 있습니다.")
                    choice = int(input("계속 진행하시겠습니까?\n1.예\n2.아니오\n>>>"))
                    if choice == 1 :
                        self.createChar()
                    elif choice == 2:
                        pass
                    else :
                        print(errMsg)
                else :
                    self.createChar()
                
            elif choice == 2:
                if self.userId not in userCharDict :
                    print("캐릭터를 먼저 생성하세요")
                else :
                    print("오늘은 뭘 하면 좋을까~~")
                    print()
                    choice = int(input(layout+"\n1.일하기\n2.능력치 강화하기\n"+layout+"\n>>>"))
                    if choice == 1:
                        #self.userId는 현재 로그인된 사용자의 객체의 userId이다.
                        #이에 대한 value는 바로 현재 로그인된 사용자의 캐릭터 객체이다.
                        if userCharDict[self.userId].play() :
                            del userCharDict[self.userId]
                    elif choice == 2:
                        userCharDict[self.userId].study()
            elif choice == 3:
                print()
                print("게임을 종료합니다",end='')
                for i in range(3) :
                    print(".",end='')
                    time.sleep(1)
                break
            else :
                print(errMsg)
                
    #까꿍 메소드
    #4줄의 코드가 각 case별로 들어가는 것보다는 메소드로 묶어주는 것이 
    #가독성에 좋을 것이라 판단하고 만들었다.            
    def ggaggung(self) :
        
        for i in range(2) :
            print("까꿍~",end='')
            time.sleep(1)
        print("나도 직업이 생겼어~!!!!")        
            
            
            
    #캐릭터 생성 메소드
    #userCharDict 딕셔너리에 key값은 현재 유저의 아이디로, value는 그 유저가 선택한 직업으로 객체생성을 해준다.
    def createChar(self) :
        
        choice = int(input(layout+"\n직업을 선택해주세요\n1.의사\n2.변호사\n3.경찰\n4.CEO\n"+layout+"\n>>>"))
        if choice == 1:
            userCharDict[self.userId] = Doctor()
            self.ggaggung()
            print("난 이제 의사야~")
        elif choice == 2:
            userCharDict[self.userId] = Lawyer()
            self.ggaggung()
            print("난 이제 변호사야~")
        elif choice == 3:
            userCharDict[self.userId] = Police()
            self.ggaggung()
            print("난 이제 경찰이야~")
        elif choice == 4:
            userCharDict[self.userId] = CEO()
            self.ggaggung()
            print("난 이제 CEO야~")
        else :
            print(errMsg)
    
        
        
        
        
#캐릭터 클래스
#게임 캐릭터는 모두 능력치, 경험치, 레벨, 가능 게임 횟수, 경험치 증가율, 성공횟수, 실패횟수를 가지고 있다.
class Character :
    
    
    
    def __init__(self, skill=50, exp=0, level=1, life=5) :
        self.skill = skill
        self.exp = exp
        self.level = level
        self.life = life
        self.successCnt = 0
        self.failCnt = 0
        
    #게임을 실행하면 개인의 능력치와 확률에 따라 성공, 실패여부가 결정된다.
    def play(self) :
        isFired = False
        #(capability)능력치는 100칸짜리 리스트에 0으로 초기화 해준 뒤, 생성될 객체의 skill(능력치)의 
        #수치만큼 각 인덱스번째 방을 1로 해준다.
        #그러면 1이 들어있는 방의 갯수는 객체의 능력치와 같다.
        capability = [0]*100
        for i in range(self.skill) :
            capability[i] = 1
            
        #100칸짜리 리스트의 길이만큼
        #즉, 0부터 100 사이의 숫자 중 랜덤한 숫자를 rand 변수에 담아준다.
        rand = random.randrange(0,len(capability)+1)
        
        #게임을 한번 실행했기 때문에 게임 가능 횟수를 1 감소시킨다.
        #만일, 가능횟수가 0이라면 억지로 광고를 보게 한다.
        
        if self.life == 0 :
            self.advertiser()
        
        self.life -= 1
        
        #성공
        #capability 리스트의 skill개의 방(초기값이라면 50개의 방)에는 1이 담겨있다.
        #만약 0에서 100 사이의 숫자중 랜덤한 숫자의 방에 담긴 수가 1이라면, 
        #skill, 즉 능력치가 높다는 것을 의미한다.
        #성공을 하면 능력치는 3 올려주고, 경험치를 경험치 증가율에 맞게 증가시켜준다.
        if capability[rand] == 1:
            self.skill += 3
            print("성공!")
            self.exp += self.expPercent
            print("남은 횟수 : "+str(self.life)+"번")
            print("현재 경험치 : "+str(self.exp))
            
            #만약 경험치가 100을 넘어가면 레벨업을 시켜준다. 
            if self.exp >= 100 :
                self.levelUp()
        #실패    
        #실패를 하면 능력치는 3 내려준다.
        else :
            self.skill -= 3
            print("실패!")
            print("남은 횟수 : "+str(self.life)+"번")
            
            #만약 능력치가 0 이하로 떨어지면 해당 객체를 삭제해준다.
            if self.skill <= 0 :
                isFired = True
                print("해고당하였습니다...")
            
        return isFired            
            
    #레벨업 메소드
    #레벨업을 하게 되면 레벨은 1 증가시키며, 게임 가능 횟수는 다시 초기화를 해준다(5번)
    #능력치도 다시 50으로 초기화 해준다.        
    def levelUp(self) :
        self.level += 1
        self.life = 5
        self.skill = 50
        self.exp = 0
        print("레벨업~~!!!!")
        print("캔디 갯수 : "+str(self.life)+"개")
       
    #강화메소드
    #강화 확률이 강화의 성공여부를 결정한다.
    #강화를 하더라도 게임 가능횟수는 줄어든다.
    #만일 게임 가능횟수가 0이라면 광고를 보게 한다.    
    def study(self) :
        winPercent = random.randrange(100)
        if self.life == 0 :
            self.advertiser()
        self.life -= 1
            
        print("능력 강화중", end='')
        for i in range(3) :
            print(".",end='')
            time.sleep(1)
        
        #확률은 50%로 해준다.
        if winPercent >= 50 :
            self.skill += 5
            
            print("강화 성공!!!")
            print("현재 능력치 : "+str(self.skill))
        else :
            print()
            print("강화 실패...")
            print("현재 능력치 : "+str(self.skill))
            
    #광고를 보여주는 메소드        
    def advertiser(self) :
        print("광고 보는 중", end='')
        for i in range(3) :
            print(".",end='')
            time.sleep(1)
        self.life += 1
        print("캔디 증가!!")
        print("캔디 갯수 : "+str(self.life)+"개")
        
        
#각 객체는 게임할 때 출력되는 값들이 다르기 때문에 play 메소드만 overriding 해준다.    
            
            
#의사
class Doctor(Character) :
    
    
    #Override
    
    def play(self) :
        isFired = False
        capability = [0]*100
        for i in range(self.skill) :
            capability[i] = 1
        rand = random.randrange(0,len(capability))
        if self.life <= 0 :
            self.advertiser()
        
        
        print("수술중",end='')
        for i in range(3) :
            print(".",end='')
            time.sleep(1.5)
        print()
        
        self.life -= 1        
        
        #성공
        if capability[rand] == 1:
            self.skill += 3
            print("환자를 살렸어요~~^ㅁ^")
            self.exp += 10
            print("캔디 갯수 : "+str(self.life)+"개")
            print("현재 경험치 : "+str(self.exp))
            
            if self.exp >= 100 :
                self.levelUp()
        #실패    
        else :
            self.skill -= 3
            print("환자가 죽었어요~~ㅠㅠ")
            print("캔디 갯수 : "+str(self.life)+"개")
            if self.skill <= 0 :
                isFired = True
                print("해고당하였습니다...")
                
        return isFired
                
#변호사
class Lawyer(Character) :
    
    #Override
    def play(self) :
        isFired = False
        capability = [0]*100
        for i in range(self.skill) :
            capability[i] = 1
        rand = random.randrange(0,len(capability))
        if self.life <= 0 :
            self.advertiser()
        
        
        print("공판중",end='')
        for i in range(3) :
            print(".",end='')
            time.sleep(1.5)
        print()
        
        self.life -= 1        
        
        #성공
        if capability[rand] == 1:
            self.skill += 3
            print("피고인이 무죄를 받았어요~~^ㅁ^")
            self.exp += 10
            print("캔디 갯수 : "+str(self.life)+"개")
            print("현재 경험치 : "+str(self.exp))
            
            if self.exp >= 100 :
                self.levelUp()
        #실패    
        else :
            self.skill -= 3
            print("피고인이 사형을 선고받았어요~~ㅠㅠ")
            print("캔디 갯수 : "+str(self.life)+"개")
            if self.skill <= 0 :
                isFired = True
                print("해고당하였습니다...") 
        return isFired
#경찰
class Police(Character) :
    
    #Override
    def play(self) :
        isFired = False
        capability = [0]*100
        for i in range(self.skill) :
            capability[i] = 1
        rand = random.randrange(0,len(capability))
        if self.life <= 0 :
            self.advertiser()
        
        
        print("출동중",end='')
        for i in range(3) :
            print(".",end='')
            time.sleep(1.5)
        print()
        
        self.life -= 1        
        
        #성공
        if capability[rand] == 1:
            self.skill += 3
            print("범인을 잡았어요~~^ㅁ^")
            self.exp += 10
            print("캔디 갯수 : "+str(self.life)+"개")
            print("현재 경험치 : "+str(self.exp))
            
            if self.exp >= 100 :
                self.levelUp()
        #실패    
        else :
            self.skill -= 3
            print("범인에게 맞았어요~~ㅠㅠ")
            print("캔디 갯수 : "+str(self.life)+"개")
            if self.skill <= 0 :
                isFired = True
                print("해고당하였습니다...")
                
        return isFired
                               
#CEO
class CEO(Character) :
    
    #Override
    def play(self) :
        isFired = False
        capability = [0]*100
        for i in range(self.skill) :
            capability[i] = 1
        rand = random.randrange(0,len(capability))
        
        
        if self.life <= 0 :
            self.advertiser()
        
        
        print("거래중",end='')
        for i in range(3) :
            print(".",end='')
            time.sleep(1.5)
        print()
        
        self.life -= 1
        
        #성공
        if capability[rand] == 1:
            self.skill += 3
            print("거래가 성공했어요~~^ㅁ^")
            self.exp += 10
            print("캔디 갯수 : "+str(self.life)+"개")
            print("현재 경험치 : "+str(self.exp))
            
            if self.exp >= 100 :
                self.levelUp()
        #실패    
        else :
            self.skill -= 3
            print("거래를 실패했어요~~ㅠㅠ")
            print("캔디 갯수 : "+str(self.life)+"개")
            if self.skill <= 0 :
                isFired = True
                print("회사가 부도났습니다...")
                
        
        return isFired




        
        
#<메인>
user = User()
#회원 정보(id, 비밀번호를 저장)
#회원의 id는 key값에, 비밀번호는 value에 저장한다.
userIdPwDict = {}

#회원 아이디, 객체 딕셔너리
#회원가입 완료 시 key값은 회원의 아이디로, value는 그 회원객체로 한다.
userDict = {}


#회원정보 : 캐릭터
#로그인 상태인 회원이 게임을 시작하여 새롭게 캐릭터를 생성할 경우 
#그 회원의 아이디를 key값으로, 회원의 캐릭터 객체를 value로 하는 딕셔너리를 만들어준다.
userCharDict = {}
layout = "="*20
wecomeMsg = "\t◈환영합니다^^◈\n"
titleMsg = "▒▒까꿍까꿍 직업체험 게임▒▒\n"
choiceMsg = "\n1.회원가입\n2.로그인\n3.나가기\n"
loginMsg = "1.내 정보\n2.내 정보 수정하기\n3.게임시작\n4.로그아웃\n"
errMsg = "다시 입력해주세요!!"
gameMsg = layout+"\n"+"1.캐릭터 생성\n2.게임하기\n3.게임종료\n"+layout+"\n>>>"
        
while True :
    
    choice = int(input(layout+"\n"+wecomeMsg+titleMsg+choiceMsg+layout+"\n>>>"))
    
    #회원가입을 실행한다.
    if choice == 1:
        user.join()
        
    #로그인을 한다.
    elif choice == 2:
        userId = input("아이디 : ")
        userPw = input("비밀번호 : ")
        
        if userId in userIdPwDict.keys() :
            
            #userDict 딕셔너리는 객체의 아이디를 key로 갖고 그 객체를 value로 받는다
            #따라서 userDict[아이디]를 활용하면 해당 객체로 접근할 수 있다.
            
            #위에서 받아온 id로 접근한 객체의 로그인 메소드를 실행한 결과 true면 다음으로 진행한다.
            if userDict[userId].login(userId, userPw) :
                while True :
                    choice = int(input(layout+"\n"+loginMsg+layout+"\n>>>"))
                    
                    if choice == 1:
                        userDict[userId].showUser()
                    elif choice == 2:
                        userDict[userId].updateUser()
                    elif choice == 3:
                        userDict[userId].gameStart()
                    elif choice == 4:
                        print("로그아웃 되었습니다.")
                        break
                    else :
                        print(errMsg)
        else :
            print("아이디가 존재하지 않습니다.")
                
    elif choice == 3:
        print("\n다음에 또 오세요ㅎㅎ")
        break
    else :
        print(errMsg)
        
        
        
        
        
        
        
        