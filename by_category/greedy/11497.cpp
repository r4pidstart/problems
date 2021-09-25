// https://www.acmicpc.net/problem/11497
// 2021-09-25 23:29:57 56ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<int> logs(n);
        for(int i=0; i<n; i++) scanf("%d", &logs[i]);
        sort(logs.begin(), logs.end());
        int l=logs[0], r=logs[1], ans=logs[1]-logs[0];
        for(int i=2; i<n; i++)
        {
            if(logs[i]-l > logs[i]-r)
            {
                ans=max(ans, logs[i]-l);
                l=logs[i];
            }
            else
            {
                ans=max(ans, logs[i]-r);
                r=logs[i];
            }
        }
        ans=max(abs(l-r), ans);
        printf("%d\n", ans);
    }
}

/*
    
*/