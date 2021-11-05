// https://www.acmicpc.net/problem/10162
// 2021-11-06 03:35:17 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n1=0, n2=0, n3=0, t; scanf("%d", &t);
    while(t>=300) n3++, t-=300;
    while(t>=60) n2++, t-=60;
    while(t>=10) n1++, t-=10;
    if(t) printf("-1");
    else printf("%d %d %d", n3, n2, n1);
}

/*
    
*/