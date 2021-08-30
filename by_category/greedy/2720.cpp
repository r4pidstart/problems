// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,a=0,b=0,c=0; scanf("%d", &n);
        if(n>=25) a+=n/25, n%=25;
        if(n>=10) b+=n/10, n%=10;
        if(n>=5) c+=n/5, n%=5;
        printf("%d %d %d %d\n", a,b,c,n);
    }
}

/*
      
*/