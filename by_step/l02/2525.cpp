// https://www.acmicpc.net/problem/2525
// 2022-02-20 14:19:59 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a,b,c; 
    scanf("%d%d%d", &a, &b, &c);
    b+=c;
    a+=b/60;
    b%=60;
    a%=24;
    printf("%d %d", a, b);
}

/*
    
*/