// https://www.acmicpc.net/problem/9996
// 2022-07-16 00:45:56
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d ", &n);
    string pat_a, pat_b;
    getline(cin, pat_a, '*');
    getline(cin, pat_b);

    while(n--)
    {
        string s; cin >> s;

        int flag=0;
        if(pat_a.length() + pat_b.length() > s.length()) flag++;
        for(int i=0; i<pat_a.length() and !flag; i++)
            if(s[i] != pat_a[i]) flag++;
        for(int i=0; i<pat_b.length() and !flag; i++)
            if(s[s.length()-1-i] != pat_b[pat_b.length()-1-i]) flag++;

        printf("%s\n", flag ? "NE":"DA");
    }
}

/*
    
*/