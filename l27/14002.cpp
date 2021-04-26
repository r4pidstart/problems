// https://www.acmicpc.net/problem/14002
// 2021-04-26 21:10:52 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    int arr[1001]={};
    vector<pair<int, int> > dp(1001,{0,0});
    // subsequence size / prev index

    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);

    pair<int,int> res={0,0};
    for(int i=1; i<=n; i++)
    {
        int max_index=0;
        for(int j=i-1; j>0; j--)
        {
            if(arr[j]<arr[i] && dp[max_index].first<dp[j].first)
                max_index=j;
        }
        dp[i]={dp[max_index].first+1, max_index};

        if(res.first<dp[i].first)
            res={dp[i].first, i};
    }
    
    int pointer=res.second;
    printf("%d\n", res.first);
    stack<int> ans;
    while(pointer!=0)
    {
        ans.push(pointer);
        pointer=dp[pointer].second;
    }

    while(!ans.empty())
    {
        printf("%d ", arr[ans.top()]);
        ans.pop();
    }
}