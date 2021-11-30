// https://www.acmicpc.net/problem/2828
// 2021-12-01 00:31:26 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m,c; scanf("%d%d%d", &n,&m,&c);
    int le=1, ri=m, ans=0;
    for(int i=0; i<c; i++)
    {
        int t; scanf("%d", &t);
        if(le<=t and t<=ri) continue;
        if(t<le) ans+=(le-t), ri-=(le-t), le-=(le-t);
        else ans+=(t-ri), le+=(t-ri), ri+=(t-ri);
    }   
    printf("%d", ans);
}
