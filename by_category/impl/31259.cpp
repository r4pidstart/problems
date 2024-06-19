// https://www.acmicpc.net/problem/31259
// 2024-05-30 03:11:41
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    vector<int> cnt(128);
    char a;
    while(cin >> a)
        cnt[a]++;
    assert(a == '@');

    for(int i=0; i<26; i++)
        cnt['A'+i]+=cnt['a'+i];

    int max_cnt=0;
    for(int i=0; i<26; i++)
        max_cnt=max(max_cnt, cnt['A'+i]);
    
    for(int i=0; i<max_cnt; i++)
    {
        for(int j=0; j<26; j++)
        {
            if((max_cnt-i)<=cnt['A'+j])
                cout << char('A'+j);
            else
                cout << ' ';
        }
        cout << '\n';
    }

    cout << "--------------------------\n";
    for(int i=0; i<26; i++)
        cout << char('A'+i);
}

/*
    
*/