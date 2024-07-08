// https://www.acmicpc.net/problem/2806
// 2024-06-25 03:56:05
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int solution(int now, int prev, const string& s)
{
    static vector<vector<int> > dp(s.size()+1, vector<int>(2, -1));
    
    if(now==s.size())
        return prev==0 ? 0:1;
    if(dp[now][prev] != -1)
        return dp[now][prev];

    int ret=INT32_MAX/2;
    // 이 글자만 바꾸기
    if(s[now]=='A' and prev==1)
        ret=min(ret, solution(now+1, prev, s)+1);
    else if(s[now]=='B' and prev==0)
        ret=min(ret, solution(now+1, prev, s)+1);
    
    // 안 바꾸기 
    if((s[now]=='A' and prev==0) or (s[now]=='B' and prev==1))
        ret=min(ret, solution(now+1, prev, s));

    // 이 글자로 바꾸기
    ret=min(ret, solution(now+1, s[now]=='A' ? 0:1, s)+1);

    return dp[now][prev]=ret;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    string s; cin >> s;

    solution(s.length()/2, 0, s);
    cout << solution(0, s[0]=='A' ? 0:1, s);
}

/*
    
*/