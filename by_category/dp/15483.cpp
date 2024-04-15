// https://www.acmicpc.net/problem/15483
// 2024-04-14 11:24:12
#include"bits/stdc++.h"
using namespace std;

// ia to ib?
int solution(int ia, int ib, const string& a, const string& b)
{
    static vector<vector<int> > dp(a.size()+1, vector<int>(b.size()+1, -1));
    if(ia==a.size() and ib==b.size())
        return ia==a.size() ? 0:INT32_MAX/2;
    if(dp[ia][ib] != -1)
        return dp[ia][ib];
    int ret=INT32_MAX/2;

    if(ia<a.size() and ib<b.size() and a[ia]==b[ib])
        ret=min(ret, solution(ia+1, ib+1, a, b));
    // modify b[bi]
    if(ia<a.size() and ib<b.size())
        ret=min(ret, solution(ia+1, ib+1, a, b)+1);
    // remove b[bi]
    if(ib<b.size())
    ret=min(ret, solution(ia, ib+1, a, b)+1);
    // insert b[bi]
    if(ia<a.size())
        ret=min(ret, solution(ia+1, ib, a, b)+1);

    return dp[ia][ib]=ret;
}

int main(void)
{
    string a,b; cin >> a >> b;
    printf("%d", solution(0, 0, a, b));
}

/*
    
*/