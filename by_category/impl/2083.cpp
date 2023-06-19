// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    while(true)
    {
        string s;
        int a,b;

        cin >> s >> a >> b;
        if(s=="#" and !a and !b) return 0;
        else if(a>17 or b>=80) cout << s << " Senior\n";
        else cout << s << " Junior\n";
    }
}

/*
    
*/