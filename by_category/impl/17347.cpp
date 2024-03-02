// https://www.acmicpc.net/problem/17347
// 2024-02-23 04:39:10
#include <bits/stdc++.h>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

int main(void)
{
#ifndef LOCAL
    cin.tie(NULL)->sync_with_stdio(false);
#endif
    int t;
    cin >> t;

    int cur=0;
    rope<char> rp;
    while(t--)
    {
        string cmd; cin >> cmd;
        if(cmd == "Move")
        {
            int k; cin >> k;
            cur=k;
        }
        else if(cmd == "Insert")
        {
            int n; string s(""), tmp; cin >> n;
            while(n)
            {
                getline(cin, tmp);
                s+=tmp;
                n-=tmp.size();
            }
            rp=rp.substr(0, cur) + s.c_str() + rp.substr(cur, SIZE_MAX/2);
        }
        else if(cmd == "Delete")
        {
            int n; cin >> n;
            rp=rp.substr(0, cur)+rp.substr(cur+n, SIZE_MAX/2);
        }
        else if(cmd == "Get")
        {
            int n; cin >> n;
            cout << rp.substr(cur, n) << '\n';
        }
        else if(cmd == "Prev")
        {
            cur--;
        }
        else if(cmd == "Next")
        {
            cur++;
        }
#ifdef LOCAL
        cout << "-- " << cmd << ' ' << rp << '\n';
#endif
    }
}