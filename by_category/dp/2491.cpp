// https://www.acmicpc.net/problem/2491
// 2021-08-29 01:02:32 12ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,prev,tmp1=1,tmp2=1,ans1=1,ans2=1; scanf("%d%d", &n, &prev);
    for(int i=0; i<n-1; i++)
    {
        int a; scanf("%d", &a);
        if(a>=prev) ans1=max(ans1, ++tmp1);
        else tmp1=1;
        if(a<=prev) ans2=max(ans2, ++tmp2);
        else tmp2=1;
        prev=a;
    }
    printf("%d", max(ans1, ans2));
}

/*
      
*/