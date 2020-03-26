#1~100까지 print()로 출력하는 메소드
#%% (1) task1
def addNum() :
    for i in range(100) :
        print(i+1, end=" ")

#1~10까지의 합을 구하는 메소드
#%% (2) task2
def sumNum() :
    result = 0
    for i in range(1,11) :
        result += i
        
    return result

#자연수를 음수로 바꿔주는 메소드
#%% (3) task3
def cngNeg(num) :
    if num > 0 :
        if num - int(num) == 0 :
            num *= -1
            print("음수로 바꾸었습니다.\n바뀐 정수:",num)
        else :
            print("자연수가 아닙니다.")
    else :
        print("자연수가 아닙니다.")
    
    return num

num = int(input("자연수를 입력해주세요!"))

cngNeg(num)

#1~n까지의 합을 print()로 출력하는 메소드
#%% (4) task4

def sumUntilNum(n) :
    result=0
    for i in range(1,n+1) :
        result += i
    return result

#홀수를 짝수로, 짝수를 홀수로 바꿔주는 메소드
#%% (5) task5
    
def cngOddEven(num) :
    if num%2 != 0 :
        num += 1
    else :
        num += 1
    
    return num

#5개의 정수를 오름차순으로 정렬해주는 메소드
#%% (6) task6


#선택정렬
def orderByAsc(numList) :
    
    for i in range (len(numList)-1) :
        for j in range (i+1, len(numList)) :
            if numList[i] <= numList[j] :
                temp = numList[i]
                numList[i] = numList[j]
                numList[j] = temp




numList = [4,2,6,5,8]
orderByAsc(numList)
print(numList)

#5개의 정수 중 최댓값과 최솟값을 구해주는 메소드
#%% (7) task7

def findMaxMin(numList) :
    
    maxNum = numList[0]
    minNum = numList[0]
    for i in range(1, len(numList)) :
        maxNum = numList[i] if maxNum <= numList[i] else maxNum
        minNum = numList[i] if minNum >= numList[i] else minNum    
        
    print("최대값은 : ",maxNum,"입니다.")
    print("최솟값은 : ",minNum,"입니다.")

numList = [4,2,6,5,8]
findMaxMin(numList)

#소문자를 대문자로 바꿔주는 메소드
#%% (8) task8
letter = input("소문자를 입력하세요")
def changeChr(letter) :
    return chr(ord(letter)-32)

changeChr(letter)

#%% (8-1) task 8-1

def changeChr(letter) :
    arSmall = []
    arCap = []
    for i in range (97,123) :
        arSmall.append(chr(i))
        arCap.append(chr(i-32))
    
    for i in letter :
        if i in arSmall :
            return arCap[arSmall.index(i)]
        elif i in arCap :
            return arSmall[arCap.index(i)]

letter = input("소문자를 입력하세요 : ")
print(changeChr(letter))






#한글을 정수로 바꿔주는 메소드
#%% (9) test

def changeToInt(arList) :
    result =""
    arKor = "영,일,이,삼,사,오,육,칠,팔,구".split(",")
    for i in arList :
        if i in arKor :
            result += str(arKor.index(i))
    return result

arList = input("한글을 입력하세요\n")
print(changeToInt(arList))








