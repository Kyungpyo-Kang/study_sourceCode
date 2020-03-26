#%% (1) formatTest
# =============================================================================
# data = "%d" %10
# print(type(data))
# <class 'str'> 
# =============================================================================
name = "강경표"
age = 10
weight = 66.775
hobby = 'piano'

print("이름 : %s" %name)
print("나이 : %d살" %age)
#print("몸무게 : %.1fkg" %weight)
print("몸무게 : %.2fkg" %weight)
print("취미 : %s" %hobby)
#%% (2) formatTest2
#사사오입 방식
#앞자리수가 짝수면 .5일 때 내림
#앞자리수가 홀수면 .5일 때 올림
# =============================================================================
# data = 4.5
# print("%.0f" %data)
# =============================================================================
#문자열값.format()
#문자열 안에 서식문자 대신 {}를 사용하고, 
#{}에 들어갈 값을 format()안에서 명시한다.
data1 = 10
data2 = 10.4231
data3 = 'A'
data4 = "ABC"
print("data1 : {}".format(data1))
print("data1 : {}\ndata2 : {}".format(data1, data2))
print("data1 : {d1}\ndata2 : {d2}".format(d1=data1,d2=data2))
print("=================================")
print("data1 : %d\n data2 : %f" %(data1, data2))
print("=================================")
print("data3 : %s" %data3)
#문자열은 %c로 표현할 수 없다.
print("data3 : %c" %data3)

print("data1 : %c" %65)
print("data1 : %c" %66) 








