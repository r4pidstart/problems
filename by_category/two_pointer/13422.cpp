// https://www.acmicpc.net/problem/13422
// 2022-06-27 23:18:13 148ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m,k; scanf("%d%d%d", &n, &m, &k);
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        arr.insert(arr.end(), arr.begin(), arr.end());

        int val=0, ans=0;
        for(int i=0; i<m; i++)
            val+=arr[i];
        int lo=0, hi=m-1;
        while(lo < n)
        {
            if(val < k) ans++;
            val-=arr[lo++], val+=arr[++hi];
        }
        if(ans and n==m) printf("1\n");
        else printf("%d\n", ans);
    }
}

/*
    
*/