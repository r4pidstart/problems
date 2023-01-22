// https://www.acmicpc.net/problem/11945
// 2023-01-23 01:21:34
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }
}

/*
    
*/