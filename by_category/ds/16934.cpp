// https://www.acmicpc.net/problem/16934
// 2022-12-22 23:05:56
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    map<string, pair<string, int> > ma;
    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        int flag=0;
        for(int i=1; i<=s.size(); i++)
        {
            string sub=s.substr(0, i);
            if(ma.find(sub) == ma.end())
            {
                if(!flag)
                {
                    flag=1;
                    ma[sub] = {s, s.size()==i}; 
                    cout << sub << '\n';
                }
                else
                    ma[sub] = {s, s.size()==i};
            }
        }
        if(!flag)
        {
            cout << s;
            if(++ma[s].second != 1)
                cout << ma[s].second;
            cout << '\n';
        }
    }
}

/*
    
*/