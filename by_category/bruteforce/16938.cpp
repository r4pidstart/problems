// https://www.acmicpc.net/problem/16938
// 2022-09-05 00:48:43 0ma
#include"bits/stdc++.h"
using namespace std;

int n,l,r,x;
vector<int> arr;

int dfs(int now, int sum, int mi, int ma, int cnt)
{
    if(now == n)
    {
        if(l<=sum and sum<=r and ma-mi >= x and cnt > 1)
            return 1;
        return 0;
    }

    int ret=0;
    ret+=dfs(now+1, sum+arr[now], min(mi, arr[now]), max(ma, arr[now]), cnt+1);
    ret+=dfs(now+1, sum, mi, ma, cnt);

    return ret;
}

int main(void)
{
    scanf("%d%d%d%d", &n, &l, &r, &x);
    arr.assign(n,0);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    printf("%d", dfs(0, 0, 1e7, 0, 0));
}

/*
    
*/