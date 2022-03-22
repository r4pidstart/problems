// https://www.acmicpc.net/problem/15663
// 2022-03-22 21:54:29 28ms
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
    set<vector<int> > se;
    for(auto& serial : ans)
    {
        if(se.find(serial) == se.end())
        se.insert(serial);
        for(int& i : serial)
            printf("%d ", i);
        printf("\n");
    }
}

/*
    
*/