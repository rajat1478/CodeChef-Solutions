#carsell
for i in range(int(input())):
    m=1000000007
    n=int(input())
    ls=list(map(int,input().split()))
    su=0
    a=0
    ls.sort()
    while a<=n-1:
        if ls[-1]-a<=0:
            ls.pop()
            a+=1
        else:
            su+=(ls[-1]-a)
            ls.pop()
            a+=1
            
    print(su % m)  
