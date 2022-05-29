// https://www.acmicpc.net/problem/1446
// 2022-05-30 02:12:06 0ms
#include"bits/stdc++.h"
using namespace std;

struct shortcut
{
    int s,e,c;
};
int main(void)
{
    int n,d; scanf("%d%d", &n, &d);
    vector<shortcut> arr(n);

    for(int i=0; i<n; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        arr.push_back({a,b,c});
    }

    vector<int> dp(d+1);

    for(int i=1; i<d+1; i++)
    {
        dp[i]=dp[i-1]+1;
        for(auto sc : arr)
        {
            if(sc.e == i)
                dp[i]=min(dp[i], dp[sc.s] + sc.c);
        }
    }
    printf("%d", dp[d]);
}

/*
    
*/