// https://www.acmicpc.net/problem/23628
// 2021-11-25 12:42:46 8ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a1,a2,a3, b1,b2,b3; cin>>a1>>a2>>a3>>b1>>b2>>b3;

    int diff=0, c=0, d=0;
    while(a1!=b1 or a2!=b2 or a3!=b3)
    {
        diff++, a3++;
        if(a3==31) a3=1, a2++;
        if(a2==13) a2=1, a1++;
        if(!(diff%360)) 
            c+=((diff/360 - 1) / 2)+15;
        if(!(diff%30)) 
            d++;

    }
    printf("%d %d\n%ddays", c, min(d, 36), diff);
}

/*
    
*/