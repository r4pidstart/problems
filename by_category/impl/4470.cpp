// https://www.acmicpc.net/problem/4470
// 2023-01-25 01:14:28
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    cin.ignore();
    for(int i=1; i<=n; i++)
    {
        string s;
        getline(cin, s);
        cout << i << ". " << s << '\n';
    }
}

/*
    
*/