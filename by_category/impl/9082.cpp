// https://www.acmicpc.net/problem/9082
// 2024-05-10 21:42:11
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<int> cnt(n+2);
        cnt[0]=100, cnt[n+1]=100;
        for(int i=1; i<=n; i++)
            scanf("%1d", &cnt[i]);
        
        vector<char> arr(n+2);
        for(int i=1; i<=n; i++)
            scanf(" %c", &arr[i]);

        int ans=0;
        for(int i=1; i<=n; i++)
        {
            if(arr[i]=='*')
                ans++, cnt[i-1]--, cnt[i]--, cnt[i+1]--;
        }

        for(int i=1; i<=n; i++)
        {
            if(arr[i]=='#' and cnt[i-1] and cnt[i] and cnt[i+1])
                ans++, cnt[i-1]--, cnt[i]--, cnt[i+1]--;
        }
        printf("%d\n", ans);
    }
}

/*
    
*/