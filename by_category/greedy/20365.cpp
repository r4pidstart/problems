// https://www.acmicpc.net/problem/20365
// 2022-06-22 23:50:13
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    string s; cin >> s;
    // 연속된 구간의 길이를 세기
    int prev=0, cnt=1;
    for(int i=0; i<n; i++)
        if(prev != s[i])
        {
            prev=s[i];
            if(prev != s[0]) cnt++;
        }
    printf("%d", cnt);
}

/*
    
*/