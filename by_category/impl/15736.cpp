// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    
    int dif=0, cnt=0;
    while(n>dif)
        cnt++, n-=(dif+1), dif+=2;
    printf("%d", cnt);
}

/*
    
*/