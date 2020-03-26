#5개의 정수 중 최댓값과 최솟값을 구해주는 메소드
#한글을 정수로 바꿔주는 메소드

#%% method task2
#def findMaxMin(arList, result) :
def findMaxMin(arList) :
    
    maxNum = numList[0]
    minNum = numList[0]
    for i in range(1, len(numList)) :
        maxNum = numList[i] if maxNum <= numList[i] else maxNum
        minNum = numList[i] if minNum >= numList[i] else minNum    
        
#    result[0] = maxNum
#    result[1] = minNum
    #return (maxNum, minNum) 소괄호 생략 가능 -> 튜플값으로 리턴
    return maxNum, minNum
    

#result = [0]*2
temp = input("정수 5개 입력").split(",")
arList = []
for i in temp :
    arList.append(int(i))

findMaxMin(arList, result)
print("최대값 : "+str(result[0]))
print("최솟값 : "+str(result[1]))
#소문자를 대문자로 바꿔주는 메소드
#%% task3
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
#%% task4

def changeToInt(arList) :
    result =""
    arKor = "영,일,이,삼,사,오,육,칠,팔,구".split(",")
    for i in arList :
        if i in arKor :
            result += str(arKor.index(i))
    return result

arList = input("한글을 입력하세요\n")
print(changeToInt(arList))

#%% class 

num1 = 10
num2 = 10

















