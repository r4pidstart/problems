// https://www.acmicpc.net/problem/1254
// 2022-07-15 04:40:56 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    string s; cin >> s;

    int len=s.length();
    while(true)
    {
        int l=0, r=len-1, flag=0;
        while(l<=r)
        {
            if(s.length() > r and s[l]!=s[r])
            {
                flag++;
                break;
            }
            l++, r--;
        }
        if(!flag)
            return !printf("%d", len);
        len++;
    }
}

/*
    
*/