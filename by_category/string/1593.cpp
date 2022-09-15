// https://www.acmicpc.net/problem/1593
// 2022-09-16 02:47:50 144ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    string s1, s2; cin >> s1 >> s2;
    vector<int> original(128), now(128);
    for(int i=0; i<s1.size(); i++)
        original[s1[i]]++, now[s2[i]]++;

    int ans=0;
    if(original == now) ans++;
    for(int i=s1.size(); i<s2.size(); i++)
    {
        now[s2[i-s1.size()]]--, now[s2[i]]++;
        if(original == now) ans++;
    }
    printf("%d", ans);
}

/*
    
*/