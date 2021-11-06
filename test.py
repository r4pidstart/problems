import sys

a,b=map(int, sys.stdin.readline().split())
table=[sys.stdin.readline().strip() for i in range(a)]


cnt=[]
for x in range(a-7):
    for y in range(b-7):
        cnt1=cnt2=0
        for i in range(x, x+8):
            for j in range(y, y+8):
                if(i&1):
                    if(j&1):
                        if(table[i][j]=='W'):
                            cnt1+=1
                        else:
                            cnt2+=1
                    else:
                        if(table[i][j]=='W'):
                            cnt2+=1
                        else:
                            cnt1+=1
                else:
                    if(j&1):
                        if(table[i][j]=='B'):
                            cnt1+=1
                        else:
                            cnt2+=1
                    else:
                        if(table[i][j]=='B'):
                            cnt2+=1
                        else:
                            cnt1+=1
        cnt.append(cnt1)
        cnt.append(cnt2)

print(min(cnt))