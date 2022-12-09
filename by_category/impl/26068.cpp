// https://www.acmicpc.net/problem/26068
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    int cnt=0;
    while(n--)
    {
        int a; scanf(" D-%d", &a);
        if(a<=90) cnt++;
    }
    printf("%d", cnt);
}

/*
    
*/