for t in range(int(input())):
    ts=int(input())
    count=0
    if ts%2!=0:
        count=ts//2
    else:
        while (ts%2==0):
            ts=ts//2
        count=ts//2    
            
        
    print(count)  
            
            
    
