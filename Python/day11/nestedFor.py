#%% (1) for test
#구구단 1단~9단까지 for문을 한번만 사용해서 출력
for i in range (90) :
    if(i%10 == 0) :
        continue
    print("%d*%d=%d" %(i//10+1, i%10, (i//10+1)*(i%10)))

#%% (2) nested for
for i in range(1, 10) :
    for j in range(1, 10) :
            print("%d*%d=%d" %(i, j, i*j))