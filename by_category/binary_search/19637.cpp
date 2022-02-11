// https://www.acmicpc.net/problem/19637
// 2022-02-11 23:40:33 92ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(NULL)->sync_with_stdio(false);
    int n,m; cin >> n >> m;
    map<int, string> ma;
    for(int i=0; i<n; i++)
    {
        int a; string s;
        cin >> s >> a;
        if(ma.find(a+1) != ma.end()) continue;
        ma[a+1]=s;
    }
    for(int i=0; i<m; i++)
    {
        int a; cin >> a;
        cout << ma.upper_bound(a)->second << '\n';
    }
}

/*
    
*/