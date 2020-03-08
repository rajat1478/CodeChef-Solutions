for i in range(int(input())):
    
    n,m=list(map(int,input().split()))
    f=list(map(int,input().split()))
    p=list(map(int,input().split()))
    
    ls=[]
    l=[]
    count=0
    for i in f:

        if i not in ls:
            ls.append(i)
            k=f.index(i)
            l.append(p[k])
            
        else:
            k=f.index(i)
            #print(k)
            ka=ls.index(i)
            l[ka]+=p[count]
        count+=1    
        #print(ls)
        #print(l)
            
    #print(ls)
    print(min(l))
