#%% (1) listTask1
#1~100까지 값 넣고 출력
numList = []
for i in range (1, 101) :
    numList.append(i)
print(numList)

#%% (2) listTask2
#1~100까지 중 짝수만 넣고 출력
numList = []
for i in range (1, 101) :
    if i%2 == 0 :
        numList.append(i)
print(numList)
#%% (3) listTask3
#A~F까지 넣고 출력
chrList = []
for i in range (6) :
    chrList.append(chr(i+65))
print(chrList)

#%% (4) listTask4
#A~F까지 중 C제외하고 출력
chrList = []
for i in range (6) :
    if i != 2 :
        chrList.append(chr(i+65))
print(chrList)
#%% (5) listTask5
#aBcDeFgHiJkLmNoPqRsTuVwXyZ 넣고 출력
chrList = []
for i in range (65, 91) :
    if i%2 == 0 :
        chrList.append(chr(i))
    else : 
        chrList.append(chr(i+32))
print(chrList)
#%% (6) listTask6
#자연수를 한글로 변경하기
# 입력 예) 1024
# 출력 예) 일영이사

numList = input("정수를 입력 : ")
kor_numList = ['영일이삼사오육칠팔구']
resultList = ""
for i in range (len(numList)) :
    resultList = kor_numList[int(numList[i])] + resultList
print(resultList)









