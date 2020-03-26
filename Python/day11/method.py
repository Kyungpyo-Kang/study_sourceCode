#%% (1) method test
#f(x) = 2x+1


# =============================================================================
# def f(x) :
#     print("f메소드 입니다.")
#     return 2*x+1
# 
# result = f(2)+5
# print(result)
# =============================================================================

#두 정수의 덧셈

def add(num1, num2) :
    print(num1+num2)

add(1,2)
#%% (2) method task1
#1~100까지 print()로 출력하는 메소드
def printNum() :
    for i in range(1,101) :
        print(i)

#1~10까지의 합을 구하는 메소드
def addNum() :
    result = 0;
    for i in range (1,11) :
        result += i
        return result


#자연수를 음수로 바꿔주는 메소드
def changePlus(num) :
    result = 1
    if num > 0 :
        return num * -1
    
    
    return result
#result = changePlus(10)
#if result < 0 :
#    print("음수로 바뀌었습니다.\n결과 : ",result)
#else :
#    print("자연수만 가능합니다.")

#1~n까지의 합을 print()로 출력하는 메소드
    
def addNum2(n) :
    
    total = 0
    if end > 1 :
        temp = n
        n = int(n)
        if temp - n == 0 :
            for i in range (1, n+1) :
                total += i
            print(total)
        else :
            print("실수는 입력할 수 없습니다.")
    else :
        print("1보다 큰 수를 입력하세요")



#홀수를 짝수로, 짝수를 홀수로 바꿔주는 메소드
    
def changeOddEven(num) :
    
    if num > -1 :
        if num%2 == 0:
            num += 1
            print("짝수를 홀수로 변경하였습니다")
        else :
            num += 1
            print("홀수를 짝수로 변경하였습니다")
    
    return num


num = int(input("0또는 자연수"))
result = changeOddEven(num) 
if result > 0 :
    if result%2 == 0 :
        print("짝수로 바뀌었습니다.")
    else :
        print("홀수로 바뀌었습니다.")
else :
    print("음수입니다.")

#%% (3) method task2
#5개의 정수를 오름차순으로 정렬해주는 메소드
numList = [0,0,0,0,0]
for i in range (5) :
    numList[i] = int(input("정수 입력"))
    
def orderByAsc(numList) :
    for i in range (len(numList)-1) :
        for j in range (i+1, len(numList)) :
            if numList[i] >= numList [j] :
                temp = numList[i]
                numList[i] = numList[j]
                numList[j] = temp
    return numList

print(orderByAsc(numList))


#5개의 정수 중 최댓값과 최솟값을 구해주는 메소드
    
def maxAndmin(numList) :
    maxNum = 0
    minNum = 0
    
    for i in range (len(numList)-1) :
        for j in range(0, len(numList)) :
            if numList[i] >= numList[j] :
                maxNum = numList[i]
                minNum = numList[j]
            else :
                maxNum = numList[j]
                minNum = numList[i]
           
    
    print("최대값은 ",maxNum,"입니다.")
    print("최솟값은 ",minNum,"입니다.")

maxAndmin(numList)
    
    
    
    
#%% (4) method task3
#소문자를 대문자로 바꿔주는 메소드
letter = input("소문자를 입력하세요")
def changeChr(letter) :
    return chr(chr(letter)-32)
#한글을 정수로 바꿔주는 메소드

def changeInt() :
    

















