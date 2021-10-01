// https://www.acmicpc.net/problem/11501
// 2021-10-02 05:45:10 1168ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<int> arr(n), max_price(n+1,0);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);

        for(int i=n-1; i>=0; i--)
            max_price[i]=max(max_price[i+1], arr[i]);
    
        long long ans=0;
        for(int i=0; i<n; i++)
        {
            if(max_price[i] != arr[i])
                ans+=max_price[i]-arr[i];
        }
        printf("%lld\n", ans);
    }
}

/*
    
*/