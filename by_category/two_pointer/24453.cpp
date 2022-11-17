// https://www.acmicpc.net/problem/24453
// 2022-11-18 01:44:47
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<int> arr(n);
    for(int i=0; i<m; i++)
    {
        int a; scanf("%d", &a);
        arr[a-1]=1;
    }
    
    int x,y; scanf("%d%d", &x, &y);
    int errcnt=0;
    for(int i=0; i<x; i++)
        if(arr[i]) errcnt++;
    
    int min_correction=INT32_MAX/2;
    for(int i=x; i<=n; i++)
    {
        min_correction=min(min_correction, errcnt);
        if(i==n) break;
        errcnt-=arr[i-x];
        errcnt+=arr[i];
    }
    printf("%d", min(m-min_correction, m-y));
}

/*
    
*/