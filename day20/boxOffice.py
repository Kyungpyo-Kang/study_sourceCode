#%% 박스오피스 역대 순위
#box = open("C:/python_1800_kpk/workspace/day20/boxOffice.txt", 'w')
#box.close()

# =============================================================================
# box = open("C:/python_1800_kpk/workspace/day20/boxOffice.txt", 'r')
# data = box.readlines()
# 
# while True :
#     print("[나가기:q]")
#     name = input("검색할 이름 입력>>>")
#     check = False
#     
#     for i in data :
#         if name in i.split("\t")[1]:
#             print(i, end='')
#             check = True
#     if not check :
#         print("검색결과 없음")
#     if name == 'q' :
#         break
# 
#     
# box.close()
# =============================================================================
# =============================================================================
# box = open("C:/python_1800_kpk/workspace/day20/boxOffice.txt", 'r')
# films = box.readlines()
# 
# film = input("수정하실 영화 제목")
# for i in films :
#     if film == i.split("\t")[1] :
#         films[film.index(i)] = i.replace(film, input("새로운 영화 제목"))
#         
# box = open("C:/python_1800_kpk/workspace/day20/boxOffice.txt", 'w')
# 
# for i in films:
#     box.write(i)
# #커서를 맨 위로    
# #box.seek(0)
# box.close()
# =============================================================================

box = open("C:/python_1800_kpk/workspace/day20/boxOffice.txt", 'r')
films = box.readlines()
result = ""
cnt = 0
for i in films :
    temp = i.split("\t")
    cnt += 1
    result += str(cnt) + "\t"
    for j in range(1, len(temp)) :
        result += temp[j]
        result += '' if j==len(temp)-1 else "\t"
        
box = open("C:/python_1800_kpk/workspace/day20/boxOffice.txt", 'w')
box.write(result)
box.close()




#    
#box = open("C:/python_1800_kpk/workspace/day20/boxOffice.txt", 'r')
#films = box.readlines()
#rank = "" 
#for i in range(len(films)) :
#    rank += films[i].split("\t")[0].replace(str(i+2), str(i+1))
#             
#box = open("C:/python_1800_kpk/workspace/day20/boxOffice.txt", 'w')
#for i in films :
#    box.write(rank)
#box.close()    













