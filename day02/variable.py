#%% (1) test
x = 10
print(type(x))
x= 10.9
print(type(x))
x= '한동석'
print(type(x))
#%% (2) test2
name = '한동석'
age = 20
height = 120.5
hobby = '피아노'

print(name)
print(age)
print(height)
print(hobby)

#%% (3) task
# =============================================================================
# 위의 소스코드에서 각 항목이 
# 어떤 것을 의미하는 지를 같이 출력
# =============================================================================
name = '한동석'
age = 20
height = 120.5
hobby = '피아노'

print('이름 : ',end = "")
print(name)
print('나이 : ',end = "")
print(age,end='살\n')
print('키   : ',end = "")
print(height,end='cm\n')
print('취미 : ',end = "")
print(hobby)



