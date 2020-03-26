#%% (1) input test
name = input("상품명 : ")
price = int(input("가격 : "))

#상품명 출력 및 상품 가격에서
#10% 할인된 금액 출력하기.
print("상품명 : "+name)
print(name+" : "+str(price*0.9), end = "")

#%% (2) input task
#정수 2개를 입력받고 덧셈, 뺄셈, 곱셈, 나눗셈
#출력하기(나눗셈은 몫과 나머지로 분리해서 출력)
num1 = int(input("첫번째 정수>>"))
num2 = int(input("두번째 정수>>"))
addResult = num1 + num2
subResult = num1 - num2
mulResult = num1*num2
divResult_value = num1//num2
divResult_rest = num1%num2

# =============================================================================
# print("덧셈 결과 : "+str(num1+num2))
# print("뺄셈 결과 : "+str(num1-num2))
# print("곱셈 결과 : "+str(num1*num2))
# print("<나눗셈 결과>")
# print("몫 : "+str(num1//num2))
# print("나머지 : "+str(num1%num2))
# =============================================================================
print("%d+%d=%d" %(num1, num2, addResult))
print("%d-%d=%d" %(num1, num2, subResult))
print("%d*%d=%d" %(num1, num2, mulResult))
print("%d//%d=%d" %(num1, num2, divResult_value))
print("%d % %d=%d" %(num1, num2, divResult_rest))
