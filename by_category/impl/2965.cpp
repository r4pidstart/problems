// https://www.acmicpc.net/problem/2965
// 2022-03-30 23:12:32 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a,b,c; scanf("%d%d%d", &a, &b, &c);
    printf("%d", max({0, c-b-1, b-a-1}));
}

/*
    
*/