from math import gcd
from functools import reduce
def lcm(denominators):
    return reduce(lambda a,b: a*b // gcd(a,b), denominators)
t=int(input())
for i in range(t):
    n,m=list(map(int,input().split()))
    a=list(map(int,input().split()))
    
    store=lcm(a)
    mx=1
    for i in range(1,m+1):
        k=a
        k.append(i)
        #print(k)
        for j in k:
            st=lcm(k)
            if st>store:
                mx=j
            #print(mx) 
        k.pop(-1)    
                
                
    print(mx)  
