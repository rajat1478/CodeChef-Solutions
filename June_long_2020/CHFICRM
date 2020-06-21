for t in range(int(input())):
    n=int(input())
    ls=list(map(int,input().split()))
    f=0
    t=0
    o,i=0,0
    while (o!=1 and i!=n): 
        if ls[i]==5:
            f+=1
        elif ls[i]==10:
            t+=1
            if f==0:
                o=1
            else:
                f-=1
        else:
            if t>0:
                t-=1
            elif f>1:
                f-=2
            else:
                o=1
        i+=1        
    if o==1:
        print("NO")
    else:
        print("YES")
