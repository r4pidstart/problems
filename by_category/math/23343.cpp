// https://www.acmicpc.net/problem/23343
// 2023-11-04 00:52:25
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string a,b; cin >> a >> b;

    for(char c : a)
        if(isalpha(c))
            return !printf("NaN");
    for(char c : b)
        if(isalpha(c))
            return !printf("NaN");
    printf("%d", stoi(a)-stoi(b));
}

/*
    
*/