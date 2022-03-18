// https://www.acmicpc.net/problem/2655
// 2022-03-19 02:36:13 0ms
#include<bits/stdc++.h>
using namespace std;

struct block
{
    int siz, height, weight, idx;
    bool operator<(const block& a) const
    {
        return this->siz > a.siz;
    }
};

int main(void)
{
    int n; scanf("%d", &n);

    vector<block> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d%d", &arr[i].siz, &arr[i].height, &arr[i].weight), arr[i].idx=i+1;
    
    sort(arr.begin(), arr.end());

    vector<int> dp(n+1, 0), weight(n+1, INT32_MAX), prev(n+1, -1);

    for(int i=1; i<=n; i++)
        for(int j=0; j<i; j++)
        {
            if(arr[i-1].weight < weight[j])
            {
                // if(arr[i-1].height + dp[j] == dp[i])
                //     weight[i]=min(weight[i], arr[i-1].weight);
                if(arr[i-1].height + dp[j] > dp[i])
                    dp[i]=arr[i-1].height + dp[j], weight[i]=arr[i-1].weight, prev[i]=j;
            }
        }

    int cur=max_element(dp.begin(), dp.end())-dp.begin();
    vector<int> ans;
    while(cur != 0)
    {
        ans.push_back(cur);
        cur=prev[cur];
    }
    printf("%d\n", ans.size());
    for(int i : ans)
        printf("%d\n", arr[i-1].idx);
}

/*
    
*/