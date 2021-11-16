// https://www.acmicpc.net/problem/2810
// 2021-11-17 02:43:43 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    string s; cin >> s;
    int lCnt=0;
    for(int i=0; i<s.length(); i++) if(s[i]=='L') lCnt++;
    printf("%d", min(n, n+1 - lCnt/2));
}

/*
    
*/