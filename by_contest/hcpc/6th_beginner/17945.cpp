// https://www.acmicpc.net/problem/17945
// 2021-10-31 00:34:14 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int b,c; scanf("%d%d", &b,&c);
    b*=2;
    int sol1=(-b+(int)sqrt(b*b - 4*c))/2;
    int sol2=(-b-(int)sqrt(b*b - 4*c))/2;
    if(sol1==sol2) printf("%d", sol1);
    else if(sol1 < sol2) printf("%d %d", sol1, sol2);
    else printf("%d %d", sol2, sol1);
}

/*
    
*/