# cook your dish here
n=int(input())
for k in range(n):
    m=int(input())
    l=[]
    for i in range(1,m+1):
        for j in range(m*i,0,-1):
#        print(j)
            l.append(j)
#     print(l)
            if(len(l)==m and i%2!=0):
                l=l[::-1]
                print(*l)
                i=i+1
                l.clear()
                break
            if(len(l)==m and i%2==0):
#          l=l[::-1]
                print(*l)
                i=i+1
                l.clear()
                break 
