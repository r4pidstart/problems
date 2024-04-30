// https://www.acmicpc.net/problem/31778
// 2024-04-30 15:45:45
#include"bits/stdc++.h"
using namespace std;

long nC2(int a)
{
    return 1L*a*(a-1)/2;
}

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    string s; cin >> s;

    int lo=0, hi=n-1;
    // find the nearest P or C
    while(lo<n and s[lo]=='P')
        lo++;
    while(hi>=0 and s[hi]=='C')
        hi--;

    while(k and lo<=hi)
    {
        if(s[lo]!='C' or s[hi]!='P')
            break;

        swap(s[lo], s[hi]);
        k--;

        while(lo<n and s[lo]=='P')
            lo++;
        while(hi>=0 and s[hi]=='C')
            hi--;
    }

    int cnt_p=0;
    long ans=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='P') cnt_p++;
        else ans+=nC2(cnt_p);
    }
    printf("%ld", ans);
}

/*

*/