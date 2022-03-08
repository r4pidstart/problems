// https://www.acmicpc.net/problem/11721
// 2022-03-08 19:21:05 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    int i=0, cnt=0;
    while(s[i])
    {
        if(cnt++%10 == 0 and i)
            cout << '\n';
        cout << s[i++];
    }
}

/*
    
*/