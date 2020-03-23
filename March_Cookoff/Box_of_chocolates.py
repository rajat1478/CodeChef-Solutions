#TLE ERROR

try:
    
    t=int(input())
    for i in range(t):
        n=int(input())
        w=list(map(int,input().split()))
    
        h=int(n/2)
        m=max(w)
        #pos=[i for i, j in enumerate(w) if j == m]
        count=0
        if m not in w[:h]:
            count+=1
        for i in range(h):
            w.insert(0,0)
            w[0]=w[-1]
            del[w[-1]]
        #print(w)
            if m not in w[:h]:
                count+=1
        print(count)        
except:
    pass
            
        
        
