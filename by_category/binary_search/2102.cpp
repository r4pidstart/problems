// https://www.acmicpc.net/problem/2102
// 2021-08-24 03:28:36 32ms
#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> jewelry;

int decision(double avg)
{
    // m개 이상의 연속된 보석의 평균 가치가 avg 이상이 되는 구간이 있는지 확인하기
    double sum1=0, sum2=0, minsum=0;
    for(int i=0; i<m-1; i++)
        sum1+=jewelry[i]-avg;

    // sum1:(jewelry[0]~[i] - avg*(i+1)) - sum2:(jewelry[0]~[j] - avg*(j+1)) > 0
    // = jewelry[j+1]~[k] - avg*(k-j) > 0
    for(int i=m-1; i<n; i++)
    {
        sum1+=jewelry[i]-avg;
        if(sum1-minsum > 0) return 1;
        sum2+=jewelry[i-m+1]-avg;
        minsum=min(minsum, sum2);
    }
    return 0;
}

double optimize()
{
    double lo=0, hi=2000;
    for(int i=0; i<100; i++)
    {
        double mid=(lo+hi)/2;
        if(decision(mid))
            lo=mid;
        else
            hi=mid;
    }
    return lo;
}

int main(void)
{
    scanf("%d%d", &n,&m);
    jewelry.assign(n,0);
    for(int i=0; i<n; i++)
        scanf("%d", &jewelry[i]);

    printf("%d", (int)(optimize()*1000 + 1e-6));
}

/*
    https://blog.naver.com/jinhan814/222156938200
*/