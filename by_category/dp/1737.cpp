// https://www.acmicpc.net/problem/1737
// 2024-05-14 17:06:43
#include"bits/stdc++.h"
using namespace std;

long solution(double n)
{
    static map<double, long> dp;

    if(n<=M_PI)
        return 1;
    if(dp.find(n) != dp.end())
        return dp[n];

    return dp[n]=(solution(n-1)+solution(n-M_PI))%(long)1e18;
}

int main(void)
{
#ifdef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    cout << solution(n);
}

/*

*/