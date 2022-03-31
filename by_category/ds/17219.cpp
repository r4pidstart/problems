// https://www.acmicpc.net/problem/17219
// 2022-04-01 03:34:14 120ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(NULL)->sync_with_stdio(false);
    int n,m; cin>>n>>m;
    unordered_map<string, string> ma;
    while(n--)
    {
        string a,b; cin>>a>>b;
        ma[a]=b;
    }
    while(m--)
    {
        string a; cin>>a;
        cout<<ma[a]<<'\n';
    }
}

/*
    
*/