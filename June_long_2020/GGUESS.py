# cook your dish here
n=int(input())
def function(beg1,end1,beg2,end2):
    # print("ANDAR AYA",beg1,end1,beg2,end2)
    if(beg1<=end1 and beg2<=end2):
        mid=(beg1+end2)//2
        print(mid)
        c=input()
        if(c=='E'):
            return -1
        if(c=='G'):
            count=0
            prev='L'
            while(beg1<=end1 and beg2<=end2):
                mid1=(beg1+end1)//2
                mid2=(beg2+end2)//2
                print(mid1)
                #+=1
                c1=input()
                if(c1=='E'):
                    return -1
                elif(c1=='G' and count==0):
                    return function(mid1+1,end1,beg2,end2)
                count=1
                if(c1=='L' and prev=='G'):
                    end1=mid1-1
                    # print("Prev wala kiya",beg1,end1,beg2,end2)
                if(c1==prev and c1=='G'):
                    beg1=mid1+1
                    return function(beg1,end1,beg2,end2)

                print(mid2)
                #+=1
                c2=input()
                prev=c2
                if(c2=='E'):
                    return -1
                elif(c1==c2):
                    if(c1=='L'):
                        end2=mid2-1 
                    else:
                        beg1=mid1+1
                    return function(beg1,end1,beg2,end2)
                elif(c1=='L' and c2=='G'):
                    end1=mid1-1
                    beg2=mid2+1
                

        else:
            count=0
            prev='G'
            while(beg1<=end1 and beg2<=end2):
                mid1=(beg1+end1)//2
                mid2=(beg2+end2)//2
                print(mid2)
                #+=1
                c1=input()
                if(c1=='E'):
                    return -1
                elif(c1=='L' and count==0):
                    return function(beg1,end1,beg2,mid2-1)
                count=1
                if(c1=='G' and prev=='L'):
                    beg2=mid2+1
                    
                if(c1==prev and c1=='L'):
                    end2=mid2-1
                    return function(beg1,end1,beg2,end2)


                print(mid1)
                #+=1
                c2=input()
                prev=c2
                if(c2=='E'):
                    return -1
                elif(c1==c2):
                    if(c1=='G'):
                        beg1=mid1+1
                    else:
                        end2=mid2-1
                    return function(beg1,end1,beg2,end2)
                elif(c1=='G' and c2=='L'):
                    end1=mid1-1
                    beg2=mid2+1

    # print("After everythin",beg1,end1,beg2,end2)
    if(beg1>end1 and beg2<=end2):
        function(beg2,(beg2+end2)//2,(beg2+end2)//2,end2)
    elif(beg2>end2 and beg1<=end1):
        function(beg1,(beg1+end1)//2,(beg1+end1)//2,end1)

function(1,n//2,n//2,n) 

