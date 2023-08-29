// https://www.acmicpc.net/problem/18427
// 2023-08-30 01:50:42
#include"bits/stdc++.h"
using namespace std;

int ans(int now, int remain_h, vector<vector<int> >& arr)
{
    static vector<vector<int> > dp(arr.size()+1, vector<int>(remain_h+1, -1));
    if(remain_h < 0) return 0;
    if(now == arr.size()) return !remain_h;
    if(dp[now][remain_h] != -1) return dp[now][remain_h];

    int ret=0;
    ret=(ret+ans(now+1, remain_h, arr))%10007;
    for(auto i : arr[now])
        ret=(ret+ans(now+1, remain_h-i, arr))%10007;
    return dp[now][remain_h]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,h; scanf("%d%d%d", &n, &m, &h);
    vector<vector<int> > arr(n);
    for(int i=0; i<n; i++)
    {
        string s;
        cin >> ws;
        getline(cin, s);
        stringstream ss(s);
        int a;
        while(ss >> a)
            arr[i].push_back(a);
    }

    printf("%d", ans(0, h, arr));
}

/*
    
*/