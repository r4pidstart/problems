// https://www.acmicpc.net/problem/1990
// 2022-11-09 00:10:21
#include"bits/stdc++.h"
using namespace std;

int is_pal(int i)
{
    string s=to_string(i);
    for(int i=-0; i<s.length()/2; i++)
        if(s[i] != s[s.length()-i-1]) return 0;
    return 1;
}

int main(void)
{
    int a,b; scanf("%d%d", &a, &b);
    vector<bool> prime_table(b+1, 1);
    prime_table[0]=prime_table[1]=0;
    for(int i=2; i*i<=b; i++)
    {
        if(prime_table[i])
            for(int j=i+i; j<=b; j+=i)
                prime_table[j]=0;
    }
    for(int i=a; i<=b; i++)
        if(prime_table[i] and is_pal(i))
            cout << to_string(i) << '\n';
    cout << "-1";
}

/*
    
*/