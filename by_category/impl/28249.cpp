// https://www.acmicpc.net/problem/28249
// 2023-07-18 04:43:53
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    map<string, int> ma;
    ma["Poblano"]=1500;
    ma["Mirasol"]=6000;
    ma["Serrano"]=15500;
    ma["Cayenne"]=40000;
    ma["Thai"]=75000;
    ma["Habanero"]=125000;

    int ans=0;
    while(n--)
    {
        string s; cin >> s;
        ans+=ma[s];
    }
    printf("%d", ans);
}

/*
    
*/