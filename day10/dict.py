#%% (1) dict test
중국집 = {"자장면" : 1500, "짬뽕" : 2500}
print(len(중국집))
print(중국집["자장면"])
print("탕수육" in 중국집)

if "자장면" in 중국집 :
    중국집["자장면"] = 4000

print(중국집)

if "탕수육" not in 중국집 :
    중국집["탕수육"] =14000
print(중국집)

#del 중국집["짬뽕"]
#print(중국집)
for i in 중국집.keys():
    print(i)

for i in 중국집.values():
    print(i)

menu = list(중국집.values())
total = 0
avg = 0.0

for i in range (len(menu)) :
    total += menu[i]

avg = float("%.2f" %(total / len(menu)))
print("평균가격 : "+str(avg)+"원")
#%% (2) dict task
#등급을 입력받아서 학점을 출력해주는 프로그램
#1 입력시 A학점입니다. 출력
#1~5등급, A~F학점 (E학점은 없다.)
#grade = {1 : 'A', 2 : 'B', 3 : 'C',4 : 'D', 5 : 'F'}
scoreDict = {}
for i in range (5) :
    scoreDict[i+1] = chr(i+66) if i == 4 else chr(i+65)
msg = "등급을 입력해주세요\n ▶"
print("▣학점계산기▣")
userGrade = int(input(msg))
#if userGrade in scoreDict :
#    print("학점은 "+str(scoreDict[userGrade])+"입니다.")

for i in range(5) :
    if userGrade == i+1 :
        print("학점은 "+scoreDict[userGrade]+"입니다.")
        break
if userGrade == 5 :
    print("넌 소중해")

#%% (3) dict test2
numDict = {"even" : [2,4,6], "odd" : [1,3,5]}
for i in numDict["even"] :
    print(i)
    
numListDict = {"1학년" : [[30,40,50], [20,50,30]]}

for i in numListDict["1학년"] :
    for j in i :
        print(j)
#%% (4)















