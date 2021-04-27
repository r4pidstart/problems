// https://www.acmicpc.net/problem/14003
// 2021-04-27 23:29:54 336ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    int arr[n+1]={};
    vector<pair<int, int> > dp(n+1,{0,0});
    // subsequence size / prev index
    vector<int> dp_num(1,INT32_MIN), dp_index(1,0);

    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);
    
    pair<int,int> max={0,0};
    // max_length / index
    for(int i=1; i<=n; i++)
    {
        int index=dp_index[lower_bound(dp_num.begin(), dp_num.end(), arr[i])-dp_num.begin()-1];
        // 이분탐색을 이용하여 찾은 주어진 수보다 작으면서 가장 큰 인덱스
        dp[i]={dp[index].first+1, index};
        if(dp_num[dp[i].first]>arr[i])
        {
            dp_num[dp[i].first]=arr[i];
            dp_index[dp[i].first]=i;
        }
        if(dp[i].first > max.first)
        {
            max={max.first+1,i};
            dp_num.push_back(arr[i]);
            dp_index.push_back(i);
        }
    }

    printf("%d\n", max.first);
    stack<int> ans;
    int pointer=max.second;
    while(pointer!=0)
    {
        ans.push(arr[pointer]);
        pointer=dp[pointer].second;
    }
    while(!ans.empty())
    {
        printf("%d ", ans.top());
        ans.pop();
    }
}