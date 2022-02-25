// https://www.acmicpc.net/problem/1475
// 2022-02-25 23:55:59 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    string s=to_string(n);
    vector<int> cnt(10,0);
    for(int i=0; i<s.length(); i++)
        cnt[s[i]-'0']++;

    cnt[6]+=cnt[9];
    cnt[9]=0;
    cnt[6]=cnt[6]&1 ? cnt[6]/2+1:cnt[6]/2;

    printf("%d", *max_element(cnt.begin(), cnt.end()));
}

/*
    
*/