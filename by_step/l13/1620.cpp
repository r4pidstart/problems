// https://www.acmicpc.net/problem/1620
// 2022-01-28 23:48:21 168ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(NULL)->sync_with_stdio(false);
    int n,m; cin >> n >> m;
    unordered_map<string, int> m1;
    unordered_map<int, string> m2;

    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        m1[s]=i+1;
        m2[i+1]=s;
    }

    for(int i=0; i<m; i++)
    {
        string s; cin >> s;
        if(isdigit(s[0]))
            cout << m2[stoi(s)] << '\n';
        else
            cout << m1[s] << '\n';
    }
}

/*
    
*/