// https://www.acmicpc.net/problem/28437
// 2024-05-19 09:30:58
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int q; cin >> q;
    vector<int> query(q);
    for(int i=0; i<q; i++)
        cin >> query[i];
    
    sort(arr.begin(), arr.end());
    
    vector<int> ans(100001);
    for(int i=1; i<100001; i++)
    {
        ans[arr[i]]+=1;
        for(int j=arr[i]+arr[i]; j<=100000; j+=arr[i])
            ans[j]+=ans[arr[i]];
    }

    for(int i=0; i<q; i++)
        cout << ans[query[i]] << ' ';
}

/*
    
*/