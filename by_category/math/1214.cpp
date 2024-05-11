// https://www.acmicpc.net/problem/1214
// 2024-05-04 15:08:40
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int d,p,q; scanf("%d%d%d", &d, &p, &q);

    if(p<q) swap(p,q);

    int cnt_p=(d-1)/p, accum_p=cnt_p*p+p;
    int ans=accum_p;

    while(accum_p and ans!=d)
    {
        accum_p-=p;
        int tmp=(d-accum_p-1)/q*q+q + accum_p;
        if(tmp==ans)
            break;

        ans=min(ans, tmp);
    }
    printf("%d", ans);
}

/*
    
*/