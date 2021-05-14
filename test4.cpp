#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll A,B,C,D;
ll get_dist(ll i, ll j)
{
    if(i>j)
        swap(i,j);
    return (((__int128)i*A+(__int128)j*B)%C)^D;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<ll> point(n,0), dist(n, 0); // 1~10000
    scanf("%lld%lld%lld%lld", &A,&B,&C,&D);
    for(int i=0; i<n; i++)
        scanf("%lld", &point[i]);

    printf("%lld", get_dist(point[5], point[0]));
    printf("%lld\n", ((((__int128)point[0]*A+(__int128)point[5]*B)%C)^D));
    printf("%lld\n", ((((__int128)point[5]*A+(__int128)point[0]*B)%C)^D));
}