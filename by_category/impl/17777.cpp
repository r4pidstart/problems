// https://www.acmicpc.net/problem/17777
// 2024-02-23 04:46:09
#include <bits/stdc++.h>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

int main(void)
{
#ifndef LOCAL
    cin.tie(NULL)->sync_with_stdio(false);
#endif

    int m; cin >> m;
    string s; cin >> s;
    rope<char> rp(s.c_str());
    rp=rp.substr(0, m);

    int n; cin >> n;
    while(n--)
    {
        int a,b,c; cin >> a >> b >> c;
        rp=rp.substr(0, c) + rp.substr(a, b-a) + rp.substr(c, SIZE_MAX/2);
        rp=rp.substr(0, m);

        cout << "--" << rp << '\n';
    }
    cout << rp;
}