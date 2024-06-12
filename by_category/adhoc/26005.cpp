// https://www.acmicpc.net/problem/26005
// 2024-06-12 02:41:41
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    if(n==1)
        return cout << 0, 0;
    cout << (n*n+1)/2;
}

/*
    
*/