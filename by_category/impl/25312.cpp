// https://www.acmicpc.net/problem/25312
// 2022-07-09 21:53:44 40ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    long long n,m; scanf("%lld%lld", &n, &m);
    vector<pair<double, pair<int,int> > > arr(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &arr[i].second.first, &arr[i].second.second);
        arr[i].first=1.*arr[i].second.first/arr[i].second.second;
    }   
    sort(arr.begin(), arr.end());

    long long total_sugar1=0, ans1=-1,ans2=-1;
    for(int i=0; i<n; i++)
    {
        if(m >= arr[i].second.first)
            total_sugar1+=arr[i].second.second, m-=arr[i].second.first;
        else
        {
            ans1=total_sugar1*arr[i].second.first + arr[i].second.second*m;
            ans2=arr[i].second.first;
            break;
        }
    }
    if(ans1 == -1)
        ans1=total_sugar1, ans2=1;

    long long tmp=gcd(ans1, ans2);
    printf("%lld/%lld", ans1/tmp, ans2/tmp);
}

/*

*/