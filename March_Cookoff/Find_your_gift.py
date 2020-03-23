t=int(input())

for i in range(t):
    x,y=0,0
    n=int(input())
    s=input()
    a,b,c,d=0,0,0,0
    
    for i in range(n):
        if s[i]=="L" and a==0:
            x-=1
        elif s[i]=="R" and a==0:
            x+=1
        elif s[i]=="U" and b==0:
            y+=1
        elif s[i]=="D" and b==0:
            y-=1
        
        if s[i]=="L" or s[i]=="R":
            a+=1
            b=0
        elif s[i]=="U" or s[i]=="D":
            b+=1
            a=0
    print(x,y)
