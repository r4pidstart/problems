// https://www.acmicpc.net/problem/1561
// 2021-07-04 01:38:33 0ms
#include<bits/stdc++.h>
using namespace std;

vector<int> times(31, 0), seq;
int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    
    seq.assign(m,0);
    for(int i=0; i<m; i++)
    {
        scanf("%d", &seq[i]);
        times[seq[i]]++;
    }

    if(n<=m)
    {
        printf("%d", n);
        return 0;
    }

    n-=m; // t=0일때 모두 탑승 가능

    long long ans, hi=30*(long long)n, lo=0; // 총 운행 시간
    while(lo<=hi)
    // parametric search
    {
        long long mid=(hi+lo)/2;
        long long tmp=0;
        for(int i=1; i<=30; i++)
            tmp+=(mid/i)*times[i];
    
        if(tmp>=n)
        {
            ans=mid;
            hi=mid-1;
        }
        else
            lo=mid+1;
    }

    int tmp=0;
    for(int i=1; i<=30; i++)
        tmp+=((ans-1)/i)*times[i];

    int last=0, i=0;
    while(tmp<n)
        if(!(ans%seq[i++]))
            last=i, tmp++;

    printf("%d", last);
}

/*

*/