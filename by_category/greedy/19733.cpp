// https://www.acmicpc.net/problem/19733
// 2023-09-30 23:45:40
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s; cin >> s;
    int cnt=0;
    for(auto c : s)
        if(c=='A') cnt++;
    
    int tmp=1;
    while(cnt>=tmp)
    {
        cnt-=tmp;
        tmp++;
    }
    printf("%d", tmp-1);
}

/*
    
*/