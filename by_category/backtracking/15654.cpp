// https://www.acmicpc.net/problem/15654
// 2021-10-19 19:51:18 52ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<int> arr(n);

    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());

    int cnt=0;
    vector<vector<int> > ans;
    do
    {
        ans.push_back({});
        for(int i=0; i<m; i++)
            ans[cnt].push_back(arr[i]);
        cnt++;
    }
    while(next_permutation(arr.begin(), arr.end()));

    ans.resize(unique(ans.begin(), ans.end())-ans.begin());
    for(auto& serial : ans)
    {
        for(int& i : serial)
            printf("%d ", i);
        printf("\n");
    }
}

/*
    
*/