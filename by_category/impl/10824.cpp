// https://www.acmicpc.net/problem/10824
// 2022-03-22 21:34:45 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string a,b,c,d; cin >> a >> b >> c >> d;
    a+=b, c+=d;
    printf("%lld", stoll(a)+stoll(c));
}

/*
    
*/