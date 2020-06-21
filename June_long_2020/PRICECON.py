# cook your dish here
for t in range(int(input())):
    n,k=list(map(int,input().split()))
    p=list(map(int,input().split()))
    count=0
    for i in range(n):
        if p[i]>k:
            count+=p[i]-k
    print(count)    
