// https://www.acmicpc.net/problem/3447
// 2023-11-04 00:55:23
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s;
    while(getline(cin, s))
    {
        auto it=s.find("BUG");
        while(it != string::npos)
        {
            s.replace(it, 3, "");
            it=s.find("BUG");
        }
        cout << s << '\n';
    }
}

/*
    
*/