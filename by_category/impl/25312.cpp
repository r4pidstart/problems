// https://www.acmicpc.net/problem/25312
// 2022-07-09 21:53:44
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<pair<double, pair<int,int> > > arr(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &arr[i].second.first, &arr[i].second.second);
        arr[i].first=1.*arr[i].second.first/arr[i].second.second;
    }   

    sort(arr.begin(), arr.end());

    int total_water=0, total_sugar1=0, total_sugar2=1;
    long long ans1=-1,ans2=-1;
    for(int i=0; i<n; i++)
    {
        if(m >= arr[i].second.first)
            total_water+=arr[i].second.first, total_sugar1+=arr[i].second.second, m-=total_water;
        else
        {
            // ts1/ts2 + s * m/w
            int tmp1=arr[i].second.second * m;
            int tmp2=arr[i].second.first;

            // ts1 + t1/t2
            ans1=total_sugar1*tmp2 + tmp1;
            ans2=tmp2;
            break;
        }
    }
    if(ans1 == -1)
        ans1=total_sugar1;

    int tmp=gcd(ans1, ans2);
    printf("%lld/%lld", ans1/tmp, ans2/tmp);
}

/*

*/