// https://www.acmicpc.net/problem/30045
// 2023-09-28 23:09:31
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    int ans=0;
    while(n--)
    {
        string s; cin >> s;
        if(s.find("OI") != string::npos or s.find("01") != string::npos)
            ans++;
    }
    printf("%d", ans);
}

/*
    
*/