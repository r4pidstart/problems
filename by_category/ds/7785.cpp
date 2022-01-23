// https://www.acmicpc.net/problem/7785
// 2022-01-23 15:00:37 196ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    map<string, int> m;
    for(int i=0; i<n; i++)
    {
        string a, b; cin >> a >> b;
        if(m.find(a) == m.end())
            m[a]=0;
        m[a]^=1;
    }
    
    for(auto it=m.rbegin(); it!=m.rend(); it++)
        if(it->second) cout << it->first << '\n';
}

/*
    
*/