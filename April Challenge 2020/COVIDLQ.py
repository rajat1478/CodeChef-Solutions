for i in range(int(input())):
    n=int(input())
    ls=list(map(int,input().split()))
    a=0
    count=0
    for i in ls:
        if i==0 and a>0:
            a-=1
            
        elif i==1 and a!=0:
            
            count=1
            
        elif i==1:
            a=5
            continue
    if count==0:        
        print("YES")       
    else:
        print("NO")
