// https://www.acmicpc.net/problem/16440
// 2024-04-19 23:13:59
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    string s; cin >> s;
    
    int lo=0, hi=0, cs=0, ck=0;
    while(hi<n)
    {
        if(cs>n/4 or ck>n/4)
        {
            if(s[lo++]=='s') cs--;
            else ck--;
        }
        else
        {
            if(s[hi++]=='s') cs++;
            else ck++;
        }

        if(cs==n/4 and ck==n/4)
        {
            if(lo==0)
                return !printf("1\n%d", hi);
            else
                return !printf("2\n%d %d", lo, hi);
        }
    }
    assert(false);
}

/*

*/