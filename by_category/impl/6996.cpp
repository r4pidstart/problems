// https://www.acmicpc.net/problem/6996
// 2022-11-13 01:05:01
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        string a,b; cin >> a >> b;
        string c=a,d=b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a==b)
            printf("%s & %s are anagrams.\n", c.c_str(), d.c_str());
        else
            printf("%s & %s are NOT anagrams.\n", c.c_str(), d.c_str());
    }
}

/*
    
*/