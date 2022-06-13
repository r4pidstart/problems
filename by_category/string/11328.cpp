// https://www.acmicpc.net/problem/11328
// 2022-06-14 00:36:45 80ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        string s1, s2; cin >> s1 >> s2;
        vector<int> s1_cnt(26), s2_cnt(26);
        for(char c : s1)
            s1_cnt[c-'a']++;
        for(char c : s2)
            s2_cnt[c-'a']++;

        if(s1_cnt == s2_cnt) printf("Possible\n");
        else printf("Impossible\n");
    }
}

/*
    
*/