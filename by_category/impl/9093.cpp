// https://www.acmicpc.net/problem/9093
// 2022-03-21 23:56:02 412ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n); getchar();
    while(n--)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        while(ss >> tmp)
        {
            reverse(tmp.begin(), tmp.end());
            cout << tmp << ' ';
        }
        cout << '\n';
    }
}

/*
    
*/