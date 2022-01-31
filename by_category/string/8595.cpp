// https://www.acmicpc.net/problem/8595
// 2022-02-01 00:05:17 196ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    string s; cin >> s;
    long long sum=0, tmp=0;

    for(int i=0; i<s.length(); i++)
    {
        if(isdigit(s[i])) tmp=tmp*10+s[i]-'0';
        else if(tmp) sum+=tmp, tmp=0;
    }
    cout << sum+tmp;
}

/*
    
*/