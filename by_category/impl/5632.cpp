// https://www.acmicpc.net/problem/5632
// 2024-02-23 04:06:02
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

    int c_cnt=0;
    vector<rope<char> > arr(1);
    while(t--)
    {
        int cmd; cin >> cmd;
        if(cmd==1)
        {
            int p; string s; cin >> p >> s;
            p-=c_cnt;
            arr.push_back(arr.back().substr(0, p) + s.c_str() + arr.back().substr(p, SIZE_MAX/2));
        } 
        else if(cmd==2)
        {
            int p, c; cin >> p >> c;
            p--;
            p-=c_cnt, c-=c_cnt;
            arr.push_back(arr.back().substr(0, p) + arr.back().substr(p+c, SIZE_MAX/2));
        }
        else if(cmd==3)
        {
            int v,p,c; cin >> v >> p >> c;
            p--;
            v-=c_cnt, p-=c_cnt, c-=c_cnt;
            for(int i=0; i<c; i++)
                if(arr[v][p+i] == 'c') c_cnt++;
            cout << arr[v].substr(p, c) << '\n';
        }
    }
}