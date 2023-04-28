// https://www.acmicpc.net/problem/10823
// 2023-04-29 00:22:18
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s="", t;
    while(cin >> t)
        s+=t;
    stringstream ss(s);
    long ans=0, tmp;
    while(ss >> tmp)
    {
        ans+=tmp;
        ss.ignore();
    }
    printf("%ld", ans);
}

/*
    
*/