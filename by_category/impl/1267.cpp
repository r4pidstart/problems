// https://www.acmicpc.net/problem/1267
// 2022-03-31 23:18:39 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    int Y=0, M=0;
    while(n--)
    {
        int a; scanf("%d", &a);
        Y+=(a/30 + 1) * 10;// Y+=(a%30) ? 10 : 0; 
        M+=(a/60 + 1) * 15;// M+=(a%60) ? 15 : 0; 
    }
    if(Y==M)
        printf("Y M %d", Y);
    else if(Y>M)
        printf("M %d", M);
    else
        printf("Y %d", Y);
}

/*
    
*/