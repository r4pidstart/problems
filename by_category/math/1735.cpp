// https://www.acmicpc.net/problem/1735
// 2021-12-21 05:47:02 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a,b,c,d; scanf("%d%d%d%d", &a,&b,&c,&d);
    int top=a*d + b*c, bottom=b*d;
    printf("%d %d", top/gcd(top,bottom), bottom/gcd(top,bottom));
}

/*
    
*/