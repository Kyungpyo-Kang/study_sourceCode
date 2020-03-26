#%% (1) List task
# =============================================================================
# 1~100까지 값 넣고 출력
# 1~100까지 중 짝수만 넣고 출력
# A~F까지 넣고 출력
# A~F까지 중 C제외하고 출력
# aBcDeFgHiJkLmNoPqRsTuVwXyZ 넣고 출력
# # 
# 자연수를 한글로 변경하기
# 입력 예) 1024
# 출력 예) 일공이사    
# "ABC"에서 B를 Z로 변경하기
# =============================================================================
# =============================================================================
# 1번
# dataList = [0]*100
# for i in range(len(dataList)) :
#     dataList[i] = i+1
# for i in dataList:
#     print(i)
# =============================================================================
# 2번
# =============================================================================
# dataList = [0]*50
# for i in range (len(dataList)) :
#     dataList[i] = (i+1)*2
# for i in dataList :
#     print(i)
#     
# =============================================================================
# 3번
# =============================================================================
# dataList = []
# for i in range(6) :
#     dataList.append(chr(i+65))
# for i in dataList :
#     print(i)
# =============================================================================
# 4번
# =============================================================================
# dataList = [""]*5
# temp = 0
# for i in range (len(dataList)) :
#     temp = i
#     temp = temp + 1 if i > 1 else temp
#     dataList[i] = chr(temp+65)
# for i in dataList:
#     print(i)
# =============================================================================
# 5번
# =============================================================================
# dataList = [""] * 26
# for i in range (len(dataList)):
#     dataList[i] = chr(i+97 if i %2 == 0 else i+65)
# for i in dataList:
#     print(i)
# =============================================================================
#%% (2) string test
#"ABC"에서 B를 Z로 바꾸기
data = "ABC"
#data[1] = 'Z' 오류
#문자열은 직접 주소에 접근하여 수정하면 안된다.
#replace()를 사용해서 새로운 List를 만들어 준다.
print(data)
data = data.replace("B","Z")
print(data)


#%% (3) list advanced task
#자연수 입력받기
#1024 >>> 1,0,2,4
#1024 %10 ==4
#1024 //10 == 102
#102 % 10 == 2
#...
msg = "자연수 입력\n"
hangle = "영일이삼사오육칠팔구"
num = 0
num = int(input(msg))
result = ""
while (num != 0) :
    result += hangle[num%10]
    num //= 10
print(result)

for i in range (len(result)-1,-1,-1) :
    print(result[i], end="")













