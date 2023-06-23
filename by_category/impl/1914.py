def hanoi(n, s, e, v):
    if(n==1):
        print(str(s)+' '+str(e));
    else:
        hanoi(n-1, s, v, e);
        hanoi(1, s, e, v);
        hanoi(n-1, v, e, s);

n=int(input());
print(2**n-1);
if(n<=20):
    hanoi(n, 1, 3, 2);