// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int s,p; scanf("%d%d", &s, &p);
    string str; cin >> str;
    int a,c,g,t; scanf("%d%d%d%d", &a, &c, &g, &t);

    map<char, int> ma;
    for(int i=0; i<p; i++)
        ma[str[i]]++;
    
    int ans=0;
    if(ma['A']>=a and ma['C']>=c and ma['G']>=g and ma['T']>=t) ans++;
    for(int i=p; i<s; i++)
    {
        ma[str[i-p]]--, ma[str[i]]++;
        if(ma['A']>=a and ma['C']>=c and ma['G']>=g and ma['T']>=t) ans++;
    }
    printf("%d", ans);
}

/*
    
*/