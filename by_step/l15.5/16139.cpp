// https://www.acmicpc.net/problem/16139
// 2022-04-23 17:48:19 164ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    vector<vector<int> > alpha_cnt(26, vector<int>(s.length()+1, 0));

    for(int i=0; i<s.length(); i++)
        for(int j=0; j<26; j++)
            alpha_cnt[j][i+1]=alpha_cnt[j][i] + (j+'a' == s[i]);
        
    int q; scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        char target; int s,e; scanf(" %c %d %d", &target, &s, &e);
        printf("%d\n", alpha_cnt[target-'a'][e+1] - alpha_cnt[target-'a'][s]);
    }
}

/*
    
*/