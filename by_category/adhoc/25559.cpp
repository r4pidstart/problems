// https://www.acmicpc.net/problem/25559
// 2022-09-14 01:43:46 132ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    if(n==1)
        return !printf("1\n");
    if(n&1)
        return !printf("-1\n");
    for(int i=0; i<n/2; i++)
        printf("%d\n%d\n", n-i*2, i*2+1);
}

/*
    
*/