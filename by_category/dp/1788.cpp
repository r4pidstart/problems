// https://www.acmicpc.net/problem/1788
// 2021-09-10 01:12:24 12ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    const int MOD=1'000'000'000, MIL=1'000'000;
    vector<int> p(2000001, 0);
    p[MIL+0]=0, p[MIL+1]=1;
    int n; scanf("%d", &n);
    if(n<0)
    {
        for(int i=1; i<=-n; i++)
            p[MIL-i]=(p[MIL-i+2]-p[MIL-i+1])%MOD;
    }
    else
    {
        for(int i=2; i<=n; i++)
            p[MIL+i]=(p[MIL+i-1]+p[MIL+i-2])%MOD;
    }
    printf("%d\n%d", p[1000000+n]<0 ? -1:(p[1000000+n]==0 ? 0:1), abs(p[1000000+n]));
}

/*

*/