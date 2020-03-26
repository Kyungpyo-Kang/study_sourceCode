#%% (1) dict test2
numDict = {"even" : [2,4,6], "odd" : [1,3,5]}
for i in numDict["even"] :
    print(i)
    
numListDict = {"1학년" : [[30,40,50], [20,50,30]]}

for i in numListDict["1학년"] :
    for j in i :
        print(j)
#%% (2) dict task
#학생 이름과 학생 점수를 입력받고
#시험과목 개수는 3개이다.
#추가하기, 수정하기, 삭제하기, 목록보기

 
scoreList = [] 
studentDict = {}
title = "▒▒학생관리프로그램▒▒\n①추가하기\n②수정하기\n③삭제하기\n④목록보기\n⑤나가기\n"
errMsg = "다시 입력하세요\n"
while True :
    
    choice = int(input(title))
    
    #추가하기
    if choice == 1 :
        name = input("학생이름을 입력해주세요\n")
        if name not in studentDict.keys() :
            score = input("다음과 같이 점수 입력 : 0,0,0\n")
            scoreList.append(score.split(","))
            studentDict[name] = scoreList
            print("추가 성공!")
        else :
            print("추가실패 : 중복된 이름")
    #수정하기
    elif choice == 2:
        choice = int(input("①학생 수정\n②점수 수정\n"))
        if choice == 1 :
            print(list(studentDict.keys()))
            name = input("수정하실 학생의 이름을 입력\n")
            if name in studentDict.keys() :
                newName = input("새로운 이름을 입력\n")
                studentDict[newName] = studentDict[name]
                del studentDict[name]
                print("수정 완료!!")
            else :
                print("학생이 없습니다.")
        elif choice == 2:
            print(list(studentDict.keys()))
            name = input("수정하실 학생의 이름을 입력\n")
            if name in studentDict.keys() :
                scoreList = []
                newScore = input("다음과 같이 점수 입력 : 0,0,0\n")
                scoreList.append(score.split(","))
                studentDict[name] = scoreList
                print("수정 완료!!")
        else :
            print(errMsg)
    #삭제하기
    elif choice == 3:
        print(list(studentDict.keys()))
        name = input("삭제하실 학생의 이름 입력\n")
        if name in studentDict :
            choice = input("정말로 삭제하시겠습니까? (y/n)\n")
            if choice == 'y' :
                del studentDict[name]
            elif choice == 'n' :
                pass
            else :
                print(errMsg)
        else :
            print("삭제 실패 : 해당 학생이 존재하지 않습니다.")
        pass
    #목록보기
    elif choice == 4:
        for name in studentDict :
            print(name)
    elif choice == 5:
        break
    else :
        print(errMsg)
