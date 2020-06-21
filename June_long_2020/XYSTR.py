# cook your dish here
for t in range(int(input())):
    s=input()
    count=0
    while (len(s)>1):
        if s[:2]=='xy'or s[:2]=='yx':
            
            s=s[2:]
            count+=1
            
        else:
            s=s[1:]
        
    print(count)   
