
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(void)
{
    ll a=474585935261,b=687616258876,c=385099936705,d=548342706698,
       e=598924357642, f=479342226273;

    printf("%lld", ((((__int128)a*b+(__int128)c*d)%e)^f));
}