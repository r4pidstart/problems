// https://www.acmicpc.net/problem/1629
// 2021-03-21 22:59:41 0ms
#include<iostream>
using namespace std;
#define ll long long

ll dc(ll a, ll b, ll c)
{
    if(b==1)
        return a%c;

    ll res=1;
    ll tmp=dc(a,b/2,c);
    if(b%2==1)
        res=((tmp*tmp%c)*a)%c;
    else // b%2==0
        res=tmp*tmp%c;
        
    return res;
}
int main(void)
{
    ll a,b,c; scanf("%lld %lld %lld", &a,&b,&c);
    
    printf("%lld", dc(a,b,c));
}