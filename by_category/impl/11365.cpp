// https://www.acmicpc.net/problem/11365
// 2022-03-26 07:10:33 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; getline(cin,s);
    while(s != "END")
    {
        reverse(s.begin(), s.end());
        cout << s << '\n';
        getline(cin,s);
    }
}

/*
    
*/