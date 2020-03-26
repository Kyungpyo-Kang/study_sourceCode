#%% (1) 자동 형변환
print(10//3)
print(10.0//3)

#%% (2) 강제 형변환(casting)
print(10//3)
print(float(10)//3)
print(int(8.59)+2.43)
print(int(8.59 + 2.43))
print(int(8.59) + int(2.43))

#%% (3) 문자 형변환(casting)
#chr(정수) : 정수에 맞는 문자로 형변환
#통채로가 문자값

#ord(문자) : 문자에 맞는 정수로 형변환
#통채로가 정수값
data = 65
print("%c" %data)

#%% (4) encryption
pw = "a1b2c3"
en_pw = ""
de_pw = ""
key = 3


for i in pw :
    en_pw += chr(ord(i)*key)

for i in en_pw :
    de_pw += chr(ord(i)//key)
    
    
print("기존 패스워드 : %s" %pw)
print("암호화된 패스워드 : %s" %en_pw)
print("복호화된 패스워드 : %s" %de_pw)

#%% 문자열 형변환
data1 = "1"
data2 = "2"
print(int(data1)+int(data2))
#print("안녕"+3) : 오류
print("안녕"*3)
#%% concatenation : 연결
name = "한동석"
age = 10
weight = 52.5496
hobby = "piano"

print("이름 : "+name)
print("나이 : "+str(age)+"살")
print("몸무게 : "+str(weight)+"kg")
print("취미 : "+hobby)








