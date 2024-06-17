// https://www.acmicpc.net/problem/20952
// 2024-05-30 16:56:08
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n,m; cin >> n >> m;
    vector<long> arr(n), cand(m);
    for(auto& a : arr)
        cin >> a;
    for(auto& b : cand)
        cin >> b;

    vector<int> cnt(7);
    for(int i=0; i<n; i++)
        cnt[arr[i]%7]++;

    // 마지막에 다 지워지는게 뭔가?
    int accum_mod=0;
    long sum=0;
    for(int i=0; i<m; i++)
    {
        int target=(accum_mod+cand[i])%7 ? 7-(accum_mod+cand[i])%7:0;
        if(cnt[target] and accumulate(cnt.begin(), cnt.end(), 0)==cnt[target])
            continue;

        accum_mod=(accum_mod+cand[i])%7;
        cnt[target]=0;
        sum+=cand[i];
    }

    vector<int> ans;
    for(int i=0; i<n; i++)
        if(cnt[arr[i]%7])
            ans.push_back((arr[i]+sum)%int(1e9+7));

    cout << ans.size() << '\n';
    for(int a : ans)
        cout << a << ' ';
}

/*
    
*/