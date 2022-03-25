// https://www.acmicpc.net/problem/13300
// 2022-03-26 07:24:12 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,k, ans=0;
    scanf("%d%d", &n, &k);
    vector<int> cnt1(7);
    vector<int> cnt2(7);
    for(int i=0; i<n; i++)
    {  
        int a,b; scanf("%d%d", &a, &b);
        if(a) cnt1[b]++;
        if(!a) cnt2[b]++;
    }

    for(int i=0; i<7; i++)
    {
        if(cnt1[i]) ans+=ceil(cnt1[i]/(double)k);
        if(cnt2[i]) ans+=ceil(cnt2[i]/(double)k);
    }
    printf("%d", ans);
}  

/*
    
*/