// https://www.acmicpc.net/problem/22973
// 2022-10-30 19:25:09
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    long n; scanf("%ld", &n);
    if(!(n&1) && n)
        return !printf("-1");
    int digit=0, cnt=0;
    n=abs(n);
    while(n)
    {
        cnt+=!(digit%2);
        n/=2;
        digit++;
    }
    printf("%d", digit);
}

/*
    
*/