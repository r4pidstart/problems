// https://www.acmicpc.net/problem/29768
// 2024-01-11 03:38:41
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int a,b; scanf("%d%d", &a, &b);
    string s="";
    for(int i=0; i<a; i++)
        s+='a';
    
    for(int i=0; i<b-1; i++)
        s[s.length()-i-1]=char('a'+(b-i-1));
    cout << s << '\n';    
}

/*

*/