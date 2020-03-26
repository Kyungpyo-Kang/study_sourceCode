#추가, 수정, 삭제, 검색, 목록

# 상품명을 담을 list
nameList = []
# 각 상품 별 가격을 담을 list
priceList = []

title = "♨폴바셋♨\n"
menu = "①추가하기\n②수정하기\n③삭제하기\n④검색하기\n⑤목록보기\n⑥나가기\n"
errMsg = "잘못 입력하였습니다."
choice = 0

# 검색된 상품의 갯수를 저장할 변수
cnt = 0
# 검색된 상품의 정보를 저장할 변수
searchList = ""

while True :
    choice = int(input(title + menu))
    
    #추가
    if choice == 1:
        #상품명과 가격을 동시에 입력받기 위해 '-'로 구분점을 준 후
        #분리한다. 분리된 후 값이 2개 이므로 list타입이고
        #0번째 방에 상품명, 1번째 방에 가격이 저장된다.
        temp = input("상품명-가격\n").split("-")
        #상품명은 중복이 되면 안되므로 중복검사를 해주고
        #중복이 없으면 그대로 append()를 사용해서 각 저장소에 추가해준다.
        if temp[0] not in nameList :
            nameList.append(temp[0])
            #가격은 추후에 연산이 필요하므로(할인, 쿠폰 등)
            #정수로 형변환 후 저장시킨다.
            priceList.append(int(temp[1]))
            print("추가 완료")
        else :
            print("추가 실패 : 중복된 상품명")
            
    #수정
    elif choice == 2:
        choice = int(input("①상품명 수정\n②가격 수정\n"))
        #상품명 수정
        if choice ==1 :
            #상품명을 입력받고 nameList에서 검사하기
            #수정할 상품이 있으면 해당 상품의 인덱스번호에 접근하여
            #새로운 상품명을 대입해준다.
            #수정할 상품이 없다면 오류 메시지 출력
            old = input("수정할 상품명 : ")
            #수정할 상품이 존재하는 지 검사
            if old in nameList :
                new = input("새로운 상품명 : ")
                #새로운 상품명이 중복되는지 검사
                if new not in nameList :
                    #수정할 상품의 인덱스에 접근하여 새로운 상품명으로 수정
                    nameList[nameList.index(old)] = new
                    print("수정 완료")
                else :
                    print("상품명이 중복됩니다.")
            else : 
                print("수정하실 상품이 존재하지 않습니다.")
        
        #가격 수정
        elif choice ==2 :
            #상품명을 입력받고 nameList에서 검사하기
            #수정할 상품이 있으면 해당 상품의 가격에 접근하여
            #새로운 가격을 대입해준다.
            #수정할 상품이 없다면 오류 메시지 출력
            old = input("수정할 상품명 : ")
            if old in nameList :
                new = int(input("새로운 가격 : "))
                if new not in nameList :
                    priceList[nameList.index(old)] = new
                    print("수정 완료")
            else : 
                print("수정하실 상품이 존재하지 않습니다.")
        
    #삭제
    elif choice == 3:
        name = input("삭제하실 상품명\n")
        #삭제할 상품이 있는지 검사
        if name in nameList :
            #상품명을 먼저 삭제하면 그 상품의 가격을 삭제할 수 없다.
            #상품명으로 가격을 찾기 때문이다.
            #따라서 가격을 먼저 삭제해주고(중복이 있어서 인덱스로 삭제)
            #그 다음 상품명을 삭제해준다.(중복이 없으니 값으로 삭제)
            del priceList[nameList.index(name)]
            nameList.remove(name)
            print("삭제 완료")
        else :
            print("삭제하실 상품이 존재하지 않습니다.")
        
    #검색
    elif choice == 4:
        searchList = ""
        cnt = 0
        choice = int(input("①상품명 검색\n②가격 검색\n"))
        
        if choice == 1:
            name = input("검색하실 상품명 : ")
            for i in nameList :
                #i가 상품 명이다.
                #문자열은 문자list이므로 검색할 상품이 문자열 안에
                #포함이 되어 있더라도 검색해준다.
                #예) '아' 입력 시 '아메리카노'로 검색됨 
                if name in i :
                    #검색결과가 있다면 searchList에 누적 연결을 하고
                    #검색 갯수(cnt)를 1 증가시킨다.
                    searchList += i+" : "+str(priceList[nameList.index(i)])
                    cnt += 1
                
                #입력한 문구가 정확하게 상품명과 일치할 때에만 검색
                #예) '아' 입력 시 '아'라는 상품만 있는지 검사한다.
#                if name == i :
#                    searchList += i+" : "+str(priceList[nameList.index(i)])+"원\n"
#                    break
                
        elif choice == 2:
            #예) 3000 입력 시 1500~4500 상품 모두 검색
            price = int(input("[오차범위 ±50%]\n검색하실 상품가격 : "))
            
            for i in range (len(priceList)):
                lowPrice = int(price*0.5)
                highPrice = int(price*1.5)
                if priceList[i] >=lowPrice and priceList[i] <= highPrice :
                    searchList += nameList[i]+" : "+str(priceList[i])+"원\n"
                    cnt += 1
        #상품명을 검색하든 가격을 검색하든
        #결과는 동일하게 출력되므로 일괄처리를 한다.            
        if len(nameList) == 0 :
            print("상품없음")
        elif searchList == "" :
            print("검색 결과 없음")
        else :
            print("검색 결과 총 "+str(cnt)+"건")
            print("상품명 : 가격")
            print(searchList)
    #목록
    elif choice == 5:
        print("상품 없음" if len(nameList) == 0 else "상품명 : 가격")
        for i in range (len(nameList)) :
            print(nameList[i]+" : "+str(priceList[i])+"원")
    #나가기
    elif choice == 6:
        break
    else :
        print(errMsg)
    
