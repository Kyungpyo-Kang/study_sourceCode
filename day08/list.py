#%% (1) list test
dataList=[2,4,5,6]
print(len(dataList))
print(dataList[2])
print(dataList)

dataList.append(7)
print(dataList)

dataList.insert(1, 3)
print(dataList)

dataList.remove(4)
print(dataList)

del dataList[4]
print(dataList)

idx = dataList.index(6)
print(idx)

dataList[0] = 20
print(dataList)


for i in range (len(dataList)) :
    print(dataList[i])
    
for i in dataList :
    print(i)
    
    
if 8 in dataList :
    idx = dataList.index(8)
else : 
    print("8이 없음")
#%% (2) split
dataList = input("정수 2개 입력 : ").split(',')    
for i in dataList:
    print(i)
#%% (3) split test

phoneList = input("전화번호 입력\n예)010-1234-1234\n").split('-')
msgList = ["통신사 번호", "앞 번호", "뒷번호"]
    
    #통신사 번호 : 010
#앞번호 : 1234
#뒷 번호 : 5678
#출력하기
 
for i in range (len(phoneList)) :
    print(msgList[i]+" : "+phoneList[i])        
#%% (4) list task
# =============================================================================
# 1~100까지 값 넣고 출력
# 1~100까지 중 짝수만 넣고 출력
# A~F까지 넣고 출력
# A~F까지 중 C제외하고 출력
# aBcDeFgHiJkLmNoPqRsTuVwXyZ 넣고 출력
# 
# 자연수를 한글로 변경하기
# 입력 예) 1024
# 출력 예) 일공이사    
# =============================================================================
numList = []
for i in range (1,101) :
    numList.append(i)
print(numList)
numList = []
for i in range(1, 101) :
    if(i%2 == 0) :
        numList.append(i)
print(numList)
        
strList = []
for i in range(6) :
    strList.append(chr(i+65))
print(strList)

strList = []
for i in range(6) :
    strList.append(chr(i+65))
    if i==2 in strList :
        continue
print(strList)

strList = []
upperChr = ""
smallChr = ""


    

    




