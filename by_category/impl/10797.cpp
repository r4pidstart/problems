// https://www.acmicpc.net/problem/10797
// 2022-03-16 23:32:08 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, cnt=0; cin >> n;
    for(int i=0; i<5; i++)
    {
        int a; cin >> a;
        if(a==n) cnt++;
    }
    cout << cnt;
}

/*
    
*/