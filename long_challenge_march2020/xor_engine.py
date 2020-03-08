try:
    t=int(input())
    for i in range(t):
        n,q=list(map(int,input().split()))
        a=list(map(int,input().split()))
        for _ in range(q):
            p=int(input())
            ls=[]
            for i in a:
                ls.append(((p | i) &  (~p | ~i)))  
        
            l=[]
            for i in ls:
                l.append(bin(i)[2:])
    
            count=0
            for i in l:
                k=i.count('1')
                if k%2==0:
                    count+=1
            even=count
            odd=n-even
            print(even,odd)
except:
    pass
        
