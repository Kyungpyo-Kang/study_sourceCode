#%% (1) while test

cnt = 0
while cnt != 10:
    cnt+=1
    print(str(cnt)+". 한동석")

#%% (2) while test2

qMsg = ("Q.다음 중 프로그래밍 언어가 아닌 것은?\n"
        +"1. JAVA\n2. 파이썬\n3. C언어\n4. 망둥어\n"
        )

while True :
    
    choice = int(input(qMsg))
    answer = 4
    
    if choice == answer :
        print("정답!")
        break
    elif choice >= 1 and choice <=4:
        print("오답")
    else: 
        print("잘못 입력하셨습니다.")