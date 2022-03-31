// https://www.acmicpc.net/problem/2846
// 2022-04-01 03:30:49 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    int prev=1001, ans=0, start=1001;
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        if(prev < a) prev=a;
        else ans=max(ans, prev-start), start=prev=a;
    }
    printf("%d", max(ans, prev-start));
}

/*
    
*/