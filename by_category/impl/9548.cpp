// https://www.acmicpc.net/problem/9548
// 2024-02-23 03:51:55
#include <bits/stdc++.h>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

int main(void)
{
    cin.tie(NULL)->sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        rope<char> rp(s.c_str());

        string cmd;
        while(cin >> cmd)
        {
            if(cmd == "END")
                break;
            else if(cmd == "I")
            {
                string r; int x;
                cin >> r >> x;
                rp.insert(x, r.c_str());
            }
            else if(cmd == "P")
            {
                int x,y; 
                cin >> x >> y;
                cout << rp.substr(x, y-x+1) << '\n';
            }
        }
    }
}