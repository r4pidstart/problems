// https://www.acmicpc.net/problem/17614
// 2022-10-24 23:52:43
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    long cnt=0;
    for(int i=1; i<=n; i++)
    {
        string s=to_string(i);
        for(auto c : s)
            if(c=='3' || c=='6' || c=='9') cnt++;
    }
    printf("%ld", cnt);
}

/*
    
*/