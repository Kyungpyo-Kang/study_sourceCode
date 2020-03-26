title = "▒ Hermes ▒\n"
main_menu = "①구매하기\n②포인트 조회\n③나가기\n"
goodbye_Msg = "복 많이 받고 또 오세요"
#대카테고리
A_category = "①Women\n②Men\n③메인메뉴로 이동\n"
#중카테고리
B_category = "①Ready-to-wear\n②Bags\n③메인메뉴로 이동\n"
#소카테고리
W_wear_C_category = "①Maxi Embroidered Pocket Dress(￦720,000)\n②Wrap coat(￦8,800,000)\n③메인메뉴로 이동\n"
M_wear_C_category = "①Quilted parka(￦6,000,000)\n②Mouline Contraste Sweater(￦2,000,000)\n③메인메뉴로 이동\n"
maxi_name = "①Maxi Embroidered Pocket Dress"
maxi_price = 720000
coat_name = "Wrap coat"
coat_price = 8800000


money = 100000000
name = ""
price = ""
errMsg = "다시 시도해주세요"

while True :
    choice = int(input(title+main_menu))
    
    if choice == 1 :
        #변수의 재사용
        #1. 메모리 관리 효율적
        #2. 가독성이 떨어진다.
        choice = int(input(A_category))
        #Nested if
        #Women
        if choice == 1 :
            choice = int(input(B_category))
            #Ready-to-wear
            if choice == 1:
                choice = int(input(W_wear_C_category))
                #드레스
                if choice == 1:
                    name = maxi_name
                    price = maxi_price
                #코트
                elif choice == 2:
                    name = coat_name
                    price = coat_price
                #메인메뉴로 이동
                elif choice == 3:
                    continue
                #그 외
                else :
                    print(errMsg)
                    continue
                
            #Bags
            elif choice == 2:
                pass
            #메인메뉴로 이동
            elif choice == 3:
                pass
            #그 외
            else :
                pass
        #Men
        elif choice == 2 :
            pass
        #메인메뉴로 이동
        elif choice == 3 :
            pass
        #그 외 
        else :
            pass
        if money < price :
            print(name+"결제 실패 : 잔액 부족")
            print("현재 잔액 : "+str(money)+"원")
        else :
            money -= price
            print(name+"결제 성공")
            print("현재 잔액 : "+str(money)+"원")
    
    elif choice == 2 :
        pass
    elif choice == 3 :
        print(goodbye_Msg)
        break
    else :
        pass
    
    #결제 영역
    
    
    
    
    