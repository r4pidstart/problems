// https://www.acmicpc.net/problem/10800
// 2022-03-31 02:20:29 108ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<pair<int,int>, int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first.second, &arr[i].first.first), arr[i].second=i;
    
    sort(arr.begin(), arr.end());
    long long total=0;
    vector<long long> sum(200001, 0), ans(n,0);

    int prev_size=0, prev_idx=0;
    for(int i=0; i<n; i++)
    {
        if(prev_size != arr[i].first.first)
        {
            for(int j=prev_idx; j<i; j++)
            {
                sum[arr[j].first.second]+=arr[j].first.first;
                total+=arr[j].first.first;
            }
            prev_size=arr[i].first.first;
            prev_idx=i;
        }
        ans[arr[i].second]=total-sum[arr[i].first.second];
    }

    for(auto i : ans)
        printf("%lld\n", i);
}

/*
    
*/