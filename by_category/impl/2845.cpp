// https://www.acmicpc.net/problem/2845
// 2022-03-17 15:20:28 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a,b; scanf("%d%d", &a, &b);
    int total=a*b;

    for(int i=0; i<5; i++)
    {
        int n; scanf("%d", &n);
        printf("%d ", n-total);
    }
}

/*
    
*/