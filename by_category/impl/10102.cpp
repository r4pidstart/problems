// https://www.acmicpc.net/problem/10102
// 2023-02-14 04:42:24
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    string s; cin >> s;
    int cnt=count_if(s.begin(), s.end(), [](char a){return a=='A';});
    if(n-cnt == cnt)
        printf("Tie");
    else if(n-cnt < cnt)
        printf("A");
    else
        printf("B");   
}

/*
    
*/