// https://www.acmicpc.net/problem/11401
// https://cocoon1787.tistory.com/284 ?? 
// https://terms.naver.com/entry.naver?docId=3533897&cid=60209&categoryId=60209
// 2021-03-22 22:03:46 32ms
#include<iostream>
using namespace std;
#define mod 1000000007

long long pow(int a, int b, int c)
{
    if(b==1)
        return a%c;

    long long tmp=pow(a,b/2,c);
    if(b%2==0)
        return tmp*tmp%c;
    else
        return tmp*tmp%c*a%c;
}

long long nCr(int n, int r)
{
    // nPr+1
    long long a=1;
    for(int i=n; i>n-r; i--)
    {
        a*=(i%mod);
        a%=mod;
    }
    
    // r factorial
    long long b=1;
    for(int i=2; i<r+1; i++)
    {
        b*=(i%mod);
        b%=mod;
    }
    
    // r!^max-2
    b=pow(b,mod-2,mod);

    return a*b%mod;
}

int main(void)
{
    int n,k; scanf("%d%d", &n,&k);
    printf("%lld", nCr(n,k));
}   