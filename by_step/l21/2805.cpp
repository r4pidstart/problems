// https://www.acmicpc.net/problem/2805
// 2021-03-27 01:20:45 244ms
#include<iostream>
#include<vector>
using namespace std;
#define ll long long
#define max(a,b) ((a)>(b)?(a):(b))


int main(void)
{
    int n, m; scanf("%d%d", &n,&m);
    vector<int> arr(n);
    ll high=0, low=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        high=max(high,arr[i]);
    }
    
    while(high-low!=1)
    {
        ll mid=(high+low)/2;

        ll require=m;
        for(int i=0; i<n; i++)
        {
            if(arr[i]-mid>0)
                require-=arr[i]-mid;
        }

        if(require>0)
            high=mid;
        else // require<=0
            low=mid;
    }
        printf("%lld", low);
}