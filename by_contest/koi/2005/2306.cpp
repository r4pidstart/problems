// https://www.acmicpc.net/problem/2306
// 2022-05-21 00:54:42 176ms
#include"bits/stdc++.h"
using namespace std;

int ans(int s, int e, const string &str)
{
    static vector<vector<int> > dp(str.length(), vector<int>(str.length()+1, -1));
    if(dp[s][e] != -1) return dp[s][e];
    if(e-s < 2) return 0;

    int ret=0;

    // 양 옆에 at나 gc가 위치하는지 확인
    if((str[s]=='a' and str[e-1]=='t') or (str[s]=='g' and str[e-1]=='c'))
        ret=max(ret, ans(s+1, e-1, str) + 2);

    // i를 기준으로 이어붙여 만들 수 있는 더 긴 스트링이 있는지 확인
    for(int i=s+1; i<e; i++)
        ret=max(ret, ans(s, i, str)+ans(i, e, str));
    
    return dp[s][e]=ret;
}

int main(void)
{
    string s; cin >> s;
    printf("%d", ans(0, s.length(), s));
}

/*
    
*/