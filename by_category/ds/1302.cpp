// https://www.acmicpc.net/problem/1302
// 2022-01-23 14:46:45 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    map<string, int> m;
    int n; scanf("%d", &n);
    int max_cnt=0;
    string ans;
    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        if(m.find(s) == m.end())
            m[s]=0;
        m[s]++;
    }
    for(auto it : m)
        if(max_cnt<it.second) ans=it.first, max_cnt=it.second;
    cout << ans;
}

/*
    
*/