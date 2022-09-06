// https://www.acmicpc.net/problem/2922
// 2022-09-06 01:44:48 0ms
#include"bits/stdc++.h"
using namespace std;

long ans(string s, int l, int n, int vowel, int consonant, long cnt)
{
    if(s.length() == n)
        return l*cnt;
    else if(s[n] != '_')
    {
        if(s[n] == 'L') l=1;
        if(s[n] == 'A' or s[n] == 'E' or s[n] == 'I' or s[n] == 'O' or s[n] == 'U')
        {
            if(vowel == 2) return 0;
            else return ans(s, l, n+1, vowel+1, 0, cnt);
        }
        else
        {
            if(consonant == 2) return 0;
            else return ans(s, l, n+1, 0, consonant+1, cnt);
        }
    }
    else
    {
        long ret=0;

        if(vowel != 2)
            ret+=ans(s, l, n+1, vowel+1, 0, cnt*5);
        if(consonant != 2)
        {
            ret+=ans(s, l, n+1, 0, consonant+1, cnt*20);
            ret+=ans(s, 1, n+1, 0, consonant+1, cnt);
        }
        return ret;
    }
}

int main(void)
{
    string s; cin >> s;
    printf("%ld", ans(s, 0, 0, 0 ,0, 1));
}

/*
    
*/