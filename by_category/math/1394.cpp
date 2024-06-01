// https://www.acmicpc.net/problem/1394
// 2024-06-01 19:12:11
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

long powmod(long a, long b)
{
    if(b==0)
        return 1;
    long tmp=powmod(a, b/2);
    if(b&1)
        return tmp*tmp%900528*a%900528;
    return tmp*tmp%900528;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    string a,b; cin >> a >> b;
    long ans=0;
    for(int i=0; i<b.size(); i++)
    {
        int idx=find(a.begin(), a.end(), b[i])-a.begin();
        ans=(ans+powmod(a.size(), b.size()-i-1)*(idx+1))%900528;
    }
    cout << ans;
}

/*
    ``
*/