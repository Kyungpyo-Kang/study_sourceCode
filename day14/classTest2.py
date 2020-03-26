#%% (1) method parameter test

#클래스의 생성자 메소드는 클래스 밖의 메소드랑 기능적 측면에서 유사하다.
#그렇기 때문에 클래스 밖 메소드의 매개변수 또한 생성자와 마찬가지로 초기화
#해줄 수 있다.
def add(num1, num2, num3=0) :
    print(num1+num2+num3)
    
add(10,3)

#%% (2) class constructor test

class Car :
    isOn = False
    #객체로 직접 접근하여 수정하고자 할 때에는
    #생성자 외부에서 선언
    
    
    #생성자 오버로딩
    #객체를 생성할 때 초기값을 정해준다.
    #명시적으로 self는 무조건 사용해준다.
    #외부에서 접근할 때도 self로 접근해준다.
    def __init__ (self, color='미지정', price=0, brand='미지정', password='0000') :
        #생성자를 통해서 초기화를 하고자 할 때에는
        #생성자 내부에서 선언
        self.brand = brand
        self.color = color
        self.price = price
        self.password = password
    
    def engineStart(self, password) :
        
        self.cnt = 0        
        
        if password == self.password :
            if not self.isOn :
                print(self.brand + "시동 켬")
                self.isOn = True
                self.cnt = 0
            else :
                print("시동이 이미 켜져있습니다.")
        else :
            self.cnt += 1
            if self.cnt == 3 :
                print("경찰 출동중")
                
                self.cnt = 0
            else :
                print("비밀번호를 다시 입력해주세요")

    def engineStop(self) :
        if self.isOn :
            print(self.brand + "시동 끔")
            self.isOn = False
        else :
            print("시동이 이미 꺼져있습니다.")
        
        

mine = Car("Red", 300000000,"Ferrari",'7777')
#mine.engineStart()
#mine.engineStart()
#mine.engineStop()
#mine.engineStop()

choice = 0 

while(True) :
    choice = int(input("1.시동켜기\n2.시동끄기\n3.나가기\n"))
    
    if choice == 1 :
        if not mine.isOn :
            pw = input("비밀번호 입력")
        mine.engineStart(pw)
        if mine.cnt == 3 :
            break
    elif choice == 2 :
        #한 번 시동을 켰다면 끌 때 break
        if mine.isOn :
            mine.engineStop()
            break
        else :
            mine.engineStop()
    else :
        break
        









