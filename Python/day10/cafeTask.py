#추가, 수정, 삭제, 검색, 목록
nameList = []
priceList = []
title = "▦▦▦스타벅스▦▦▦\n"
menu = "①추가하기\n②수정하기\n③삭제하기\n④검색하기\n⑤목록보기\n⑥나가기\n"
errMsg = "잘못 입력하셨습니다."

while True :
    choice = int(input(title+menu))
    
    if choice == 1 :
        temp = input("상품명-가격\n").split("-")
        if temp[0] not in nameList :
            nameList.append(temp[0])
            priceList.append(int(temp[1]))
            print("추가 완료!!")
        else :
            print("추가 실패 : 중복된 상품명")
    elif choice == 2 :
        checkMsg = "수정 완료!\n\n<수정 내역>"
        name = input("수정하실 상품명 입력 : ")
        if name in nameList :
            print("\n<수정하실 상품>")
            print(name+" : "+str(priceList[nameList.index(name)]))
            choice = int(input("①상품명 수정\n②가격 수정\n"))
            if choice == 1 :
                    newName = input("새로운 상품명 입력 : ")
                    if newName not in nameList :
                        nameList[nameList.index(name)] = newName
                        print(checkMsg)
                        print("상품명 : "+name+" → "+nameList[nameList.index(newName)])
                    else : 
                        print("수정실패 : 중복된 상품명")
            else :
                    price = str(priceList[nameList.index(name)])
                    newPrice = int(input("새로운 상품 가격 입력 : "))
                    priceList[nameList.index(name)] = newPrice
                    print(checkMsg)
                    print("상품가격 : "+price+" → "+str(priceList[nameList.index(name)]))
        else :
            print("상품이 존재하지 않습니다.")
        
    elif choice == 3 :
        name = input("삭제하실 상품명 : ")
        if name in nameList :
            del priceList[nameList.index(name)]
            nameList.remove(name)
            print("삭제 완료")
    elif choice == 4 :
        cnt = 0
        searchList = ""
        choice = int(input("①상품명 검색\n②가격 검색\n"))
        if choice == 1:
            name = input("<검색하실 상품명>\n")
            for i in nameList :
                if name in i :
                    searchList += i + " : " + str(priceList[nameList.index(i)]) + "원"
                    cnt += 1
                        
        elif choice == 2:
            price = int(input("<검색하실 가격>\n※오차범위 : ±30%\n"))
            for i in range (len(priceList)) :
                lowPrice = price*(0.3)
                highPrice = price*(1.3)
                if price >= lowPrice and price <= highPrice :
                    searchList += nameList[i]+" : "+str(priceList[i])+"원\n"
                    cnt += 1
                    
        if len(nameList) == 0 :
            print("검색하실 상품이 없습니다.")
        elif searchList == "" :
            print("상품명이 존재하지 않습니다.")
        else :
            print("검색 건수 :"+str(cnt)+"건")
            print("상품명 : 가격")
            print(searchList)
            
    elif choice == 5 :
        print("목록 없음" if len(nameList)==0 else "<상품명 : 가격>")
        print()
        for i in range (len(nameList)) :
            print(nameList[i]+" : "+str(priceList[i])+"원")
    elif choice == 6 :
        break
    else : 
        print(errMsg)
    