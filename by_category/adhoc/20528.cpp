// https://www.acmicpc.net/problem/20528
// 2023-12-04 23:52:52
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    string s; cin >> s;
    for(int i=0; i<n-1; i++)
    {
        string ss; cin >> ss;
        if(ss[0] != s[0])
            return !printf("0");
    }
    printf("1");
}

/*
    
*/