#%% (1) 대소비교
#두 정수 입력받기
num1Msg = "첫번째 정수 : "
num2Msg = "두번째 정수 : "
num1 = int(input(num1Msg))
num2 = int(input(num2Msg))

result = "큰 값 :"+str(num1) if num1 > num2 else "두 수가 같습니다." if num1==num2 else num2
print(result)

#%% (2) 퀴즈게임
#Q. 다음 중 프로그래밍 언어가 아닌 것은?
#1. JAVA
#2. 파이썬
#3. C언어
#4. 망둥어

userAnswer = ""
answer = 3
answerMsg = "정답 번호를 입력해주세요 : "
result = ""
    
print("*"*10+"퀴즈게임"+"*"*10)
print("Q. 다음 중 강사님의 이름은?")
print("1. 강동원\n2. 원빈\n3. 한동석\n4. 임꺽정\n")
print("*"*30)
        
userAnswer = int(input(answerMsg))
result = "정답!!" if userAnswer == answer else "정답 범위를 벗어났습니다." if userAnswer >4 or userAnswer < 1 else "틀렸습니다."
print(result)

#%% (3) 혈액형별 성격
qMsg = ("당신의 혈액형은?\n"
        +"1. A형\n2. B형\n3. O형\n4. AB형\n"
        )
answer_a = "세심하고 거짓말을 잘 못한다."
answer_b = "거침없고 추진력이 좋다."
answer_o = "사교성이 좋고 폭발한다."
answer_ab = "이상하다."
errMsg = "잘못 입력하셨습니다."
choice = int(input(qMsg))

print((answer_a if choice == 1 else
 answer_b if choice == 2 else
 answer_o if choice == 3 else
 answer_ab if choice == 4 else errMsg))





