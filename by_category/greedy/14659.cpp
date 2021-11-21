// https://www.acmicpc.net/problem/14659 
// 2021-11-21 03:17:09 4ms
#include<iostream>
using namespace std;

#define max(a,b) (a>b ? a:b)

int main(void)
{
    int n; scanf("%d", &n);
    int ans=0, prevMax=0, prevAns=0;
    for(int i=0; i<n; i++)
    {
        int tmp; scanf("%d", &tmp);
        if(tmp>prevMax) prevMax=tmp, prevAns=max(prevAns, ans), ans=0;
        else if(prevMax > tmp) ans++;
    }
    printf("%d", max(prevAns, ans));
}

/*
    
*/