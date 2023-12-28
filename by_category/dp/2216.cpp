// https://www.acmicpc.net/problem/2216
// 2023-12-25 00:22:09
#include"bits/stdc++.h"
using namespace std;

int ans(const string& s1, const string& s2, int x, int y, int a, int b, int c)
{
    static vector<vector<int> > memo(x+1, vector<int>(y+1, INT32_MAX/2));
    if(x==0 and y==0) return 0;
    if(memo[x][y] != INT32_MAX/2) return memo[x][y];
    
    int ret=INT32_MIN;

    if(x)
        ret=max(ret, ans(s1, s2, x-1, y, a, b, c)+b);
    if(y)
        ret=max(ret, ans(s1, s2, x, y-1, a, b, c)+b);
    if(x and y)
        ret=max(ret, ans(s1, s2, x-1, y-1, a, b, c)+(s1[x-1]==s2[y-1] ? a : c));
    
    return memo[x][y]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int a,b,c; scanf("%d%d%d", &a, &b, &c);
    string s1, s2; cin >> s1 >> s2;

    printf("%d", ans(s1, s2, s1.length(), s2.length(), a, b, c));
}

/*
    
*/