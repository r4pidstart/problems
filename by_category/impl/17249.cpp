// https://www.acmicpc.net/problem/17249
// 2023-12-18 23:20:54
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s; cin >> s;
    vector<int> cnt(2);
    int t=0;
    for(char c : s)
    {
        if(c=='0') t=1;
        if(c=='@') cnt[t]++;
    }
    printf("%d %d", cnt[0], cnt[1]);
}

/*
    
*/