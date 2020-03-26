#%% (1) if문 테스트
num1Msg = "첫번째 정수 : "
num2Msg = "두번째 정수 : "

num1 = int(input(num1Msg))
num2 = int(input(num2Msg))

if num1 > num2 :
    print("큰 수 :"+str(num1))
elif num2 != num1 :
    print("큰 수 :"+str(num2))
else :
    print("두 수가 같습니다.")

#%% (2) 혈액형별 성격
qMsg = ("당신의 혈액형은?\n"
        +"1. A형\n2. B형\n3. O형\n4. AB형\n"
        )
answer_a = "세심하고 거짓말을 잘 못한다."
answer_b = "거침없고 추진력이 좋다."
answer_o = "사교성이 좋고 폭발한다."
answer_ab = "이상하다."
errMsg = "잘못 입력하셨습니다."
choice = int(input(qMsg))

resultMsg = ""

if choice == 1 :
    resultMsg = answer_a
elif choice == 2 :
    resultMsg = answer_b
elif choice == 3 :
    resultMsg = answer_o
elif choice == 4 :
    resultMsg = answer_ab
else :
    resultMsg = errMsg

print(resultMsg)


