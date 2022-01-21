// https://www.acmicpc.net/problem/16994
// 2022-01-22 00:07:11 232ms
#include <bits/stdc++.h>
#include <ext/rope> 

using namespace std;
using namespace __gnu_cxx;

int main(void)
{
  cin.tie(NULL)->sync_with_stdio(false);
  string s; cin >> s;
  rope<char> rp(s.c_str());

  int q; cin >> q;
  for(int i=0; i<q; i++)
  {
    int cmd; cin >> cmd;
    switch(cmd)
    {
      case 1:
      {
        int a,b; cin >> a >> b;
        rp = rp.substr(a, b-a+1) + rp.substr(0, a) + rp.substr(b+1, s.length());

        // cout << rp << '\n';
        break;
      }
      case 2:
      {
        int a,b; cin >> a >> b;
        rp = rp.substr(0, a) + rp.substr(b+1, s.length()) + rp.substr(a, b-a+1);

        // cout << rp << '\n';
        break;
      }
      case 3:
      {
        int a; cin >> a;
        cout << rp[a] << '\n';
        break;
      }
    }
  }
}

/*
    http://gcc.gnu.org/onlinedocs/gcc-4.6.3/libstdc++/api/a00065.html
    https://www.secmem.org/blog/2019/03/09/rope/
*/