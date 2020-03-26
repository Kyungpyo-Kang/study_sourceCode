#%% (1) file test

name_file = open("C:/python_1800_kpk/workspace/names.txt", 'w')
name_file.write("강경표")
name_file.close()

name_file = open("C:/python_1800_kpk/workspace/names.txt", 'r')

data = name_file.readlines()
print(data[0], end='')
#%% (2) 한국인의 이름통계
name_file = open("C:/python_1800_kpk/workspace/names.txt", 'r')
data = name_file.readlines()

name = input("검색할 이름 : ")


check = False

for i in data :
    if name == i.split('\t')[0] :
        print(i, end='')
        check = True
if not check :
    print("검색결과 없음")
    
