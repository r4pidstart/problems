// https://www.acmicpc.net/problem/1053
// 2023-02-22 04:06:47
#include"bits/stdc++.h"
using namespace std;

int solution(string& s, int l, int r, int reset=0)
{
    static vector<vector<int> > dp;

    if(reset)
        dp.assign(s.length(), vector<int>(s.length(), -1));

    if(r<=l)
        return 0;
    if(dp[l][r] != -1)
        return dp[l][r];
    
    return dp[l][r]=min({solution(s, l+1, r)+1, solution(s, l, r-1)+1, solution(s, l+1, r-1)+(s[l]!=s[r])});
}

int main(void)
{
#ifdef LOCAL
#endif
    string s; cin >> s;
    int ret=solution(s, 0, s.length()-1, 1);
    for(int i=0; i<s.length(); i++)
        for(int j=i+1; j<s.length(); j++)
        {
            swap(s[i], s[j]);
            ret=min(ret, solution(s, 0, s.length()-1, 1)+1);
            swap(s[i], s[j]);
        }
    printf("%d", ret);
}

/*
    
*/