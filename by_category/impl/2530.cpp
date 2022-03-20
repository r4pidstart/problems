// https://www.acmicpc.net/problem/2530
// 2022-03-20 14:11:42 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int h,m,s; scanf("%d%d%d", &h, &m, &s);
    int req; scanf("%d", &req);

    s+=req;
    m+=s/60;
    s%=60;

    h+=m/60;
    m%=60;

    h%=24;
    printf("%d %d %d", h, m, s);
}

/*
    
*/