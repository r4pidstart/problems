// https://www.acmicpc.net/problem/1769
// 2022-12-14 02:18:12
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s; cin >> s;
    int cnt=0;
    while(s.size() != 1)
    {
        cnt++;
        int tmp=0;
        for(char c : s)
            tmp+=c-'0';
        s=to_string(tmp);
    }
    printf("%d\n", cnt);
    if(stoi(s) % 3)
        printf("NO");
    else
        printf("YES");
}

/*
    
*/