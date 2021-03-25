// https://www.acmicpc.net/problem/1654
// 2021-03-26 02:41:13 4ms
#include<iostream>
#include<vector>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define ll long long

vector<ll> arr;

int main(void)
{
    ll k, n, max_l=0; scanf("%lld%lld", &k, &n);
    arr.resize(k);
    for(ll i=0; i<k; i++)
    {
        scanf("%lld", &arr[i]);
        max_l=max(max_l, arr[i]);
    }
    ll res=0, start=1, end=max_l;
    while(start<=end)
    {
        ll mid=(start+end)/2;
        ll count=0;

        for(int i=0; i<k; i++)
        {
            count+=arr[i]/mid;
            if(count>=n)
                break;
        }
        if(count>=n)
        {
            start=mid+1;
            res=mid;
        }
        else
            end=mid-1;
    }

    printf("%lld", res);
}