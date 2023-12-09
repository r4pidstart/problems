// https://www.acmicpc.net/problem/30884
// 2023-12-08 21:37:52
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s; cin >> s;

    printf("%c", s[0]);
    for(int i=1; i<s.length(); i++)
    {
      if(s[i-1]=='(' and s[i]==')')
        printf("1)");
      else if(s[i-1]==')' and s[i]=='(')
        printf("+(");
      else
        printf("%c", s[i]);
    }
}

/*
    
*/