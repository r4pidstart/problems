// https://www.acmicpc.net/problem/2480
// 2022-02-21 19:13:11 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a,b,c; scanf("%d%d%d", &a, &b, &c);
    // 3개 동일
    if (a==b and b==c)
        printf("%d", a*1000+10000);
    else if(a==b or b==c or a==c)
    {
        int same;
        if(a==b) same = a;
        if(b==c) same = b;
        if(a==c) same = a;
        printf("%d", same*100+1000);
    }
    else
        printf("%d", max({a,b,c})*100);
}

/*
    
*/