
#%% 모여라 셀럽동물 게임
import time
import random as r
#동물 클래스


#먹기()
#HP1증가
#먹이 1 감소
#자기()
#산책하기()
    
class Animal() :
    
    def __init__(self, nickname="",hp=0,foodCnt=0,foodType="") :
    #닉네임
        self.nickname = nickname
    #체력
        self.hp = hp
    #먹이개수
        self.foodCnt = foodCnt
    #먹이 종류
        self.foodType = foodType
    
    def eat(self, food) :
        if self.foodCnt < 1 :
            print("먹이가 부족합니다. 산책 다녀오세요")
        else :
            if food == self.foodType :
                self.foodCnt -= 1
                self.hp += 1
                print("hp증가!!")
                print("맛있당~~'ㅁ'")
                print("현재 hp : "+str(self.hp))
                print("남은 먹이 갯수 : "+str(self.foodCnt))
            else :
                self.hp -= 1
                print("hp감소!!")
                print("맛없어!!")
                print("현재 hp : "+str(self.hp))
                print("남은 먹이 갯수 : "+str(self.foodCnt))
                if self.hp == 0 :
                     Animal.sleep(self)
            
    
    def sleep(self) :
        print("쿨쿨", end='')
        for i in range(3) :
            print(".",end='')
            #1초씩 3번 반복(총 3초 멈춤)
            time.sleep(1)        
        self.hp += 1
        print("\nhp 증가!!")
        print("현재 hp : "+str(self.hp))
        
        
    def walk(self, qDict) :
        #모든 객체가 문제를 공유하기 때문에
        #클래스 내부에서 필드로 만들필요 없다.
        #따라서 외부에서 전달받는다.
        if self.hp < 2 :
            print("체력이 부족해요! 먹거나 자고 오세요!!")
        else :
            #산책시 hp가 바로 1 감소
            self.hp -= 1
            
            #문제를 랜덤하게 출력하기 위해서
            #key값만 인덱스를 부여해준다.
            arQue = list(qDict.keys())
            
            #문제 갯수만큼만 랜덤한 값을 가져온다.
            idx = r.randrange(0, len(arQue))
            print(arQue[idx])
            
            #랜덤한 인덱스에 있는 문제가 출력된다.
            answer = int(input("여기에 정답 입력>>>"))
            
            #딕셔너리에 문제(key값)를 전달하면 그 문제의
            #정답을 가져온다. 따라서 사용자가 입력한 값과
            #문제의 정답을 비교한다.
            if answer == qDict[arQue[idx]] :
                print("정답!!")
                self.foodCnt += 2
            else :
                print("오답!!")
                self.hp -= 1
                if self.hp == 0 :
                    #체력이 0이 되면 자동으로 잠자기를 해준다.
                    Animal.sleep(self)
        

menu = "[캐릭터 선택]\n1.토끼\n2.양\n3.사슴\n4.나가기\n"
choiceMenu = "1.밥먹기\n2.산책하기\n3.잠자기\n4.메인메뉴로 이동\n"

rabbit = Animal("총총이", 3, 7, "당근")
sheep = Animal("복슬이", 5, 5, "풀")
deer = Animal("밤비", 7, 3, "도토리")

#각 객체명은 규칙성이 없기 때문에 list에 담고 규칙성을
#부여해준다.
arAnimal = [rabbit, sheep, deer]


qDict = {}

q1 = ("Q. 다음 중 동물이 아닌 것은?\n"
    +"1.강아지\n2.사람\n3.형광등\n4.토끼\n")
q2 = ("Q.다음 중 못된 일을 한 학생은?\n"
    +"1.철수 : 엄마 설거지를 도와드렸어요.\n"
    +"2.영희 : 할머니 짐을 옮겨드렸어요.\n"
    +"3.민수 : 빨래를 개켰어요.\n"
    +"4.민호 : 동생을 때렸어요.\n")

q3 = ("Q.1 다음 숫자는?\n"
      +"1.2\n2.3\n3.4\n4.-95\n")

a1 = 3
a2 = 4
a3 = 1

qDict[q1] = a1
qDict[q2] = a2
qDict[q3] = a3

while True :
    
    #choice는 사용자가 선택한 동물의 번호이다.
    #따라서 재사용을 하면 안된다.
    choice = int(input(menu))
    if choice == 4 :
        print("다음에 또 만나요~")
        break
    
    if choice == 1:
        pass
    elif choice == 2 :
        pass
    elif choice == 3:
        pass
    else :
        print("다시입력해주세요")
    
    while True :
        menu_choice = int(input(choiceMenu))
        
        if menu_choice == 1:
            #사용자가 메인 메뉴에서 선택한 chocie에
            #-1을 해줘야 인덱스 번호가 되고 
            #그 곳에 있는 동물이 바로
            #사용자가 선택한 캐릭터이다.
            food = input("먹이를 입력하세요!")
            arAnimal[choice-1].eat(food)
        elif menu_choice == 2 :
            arAnimal[choice-1].walk(qDict)
        elif menu_choice == 3 :
            arAnimal[choice-1].sleep()
        elif menu_choice == 4 :
            break













