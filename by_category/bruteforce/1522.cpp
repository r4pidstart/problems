// https://www.acmicpc.net/problem/1522
// 2022-09-10 22:08:13 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    string s; cin >> s;

    int b_cnt=count_if(s.begin(), s.end(), [&](char c){return c=='b';});
    s+=s;
    int ans=0;
    for(int i=0; i<s.length()/2; i++)
    {
        int tmp=count_if(s.begin()+i, s.begin()+i+b_cnt, [&](char c){return c=='b';});
        ans=max(ans, tmp);
    }
    printf("%d", ans==INT32_MAX ? 0:b_cnt-ans);          
}

/*
    
*/