// https://www.acmicpc.net/problem/11444
// 2021-03-24 00:10:59 0ms
#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
#define max 1000000007

ll arr[2][2]={1,1,1,0}, res[2][2]={1,1,1,0};

int multiply(ll arr_a[][2], ll arr_b[][2])
{
    ll tmp[2][2]={};
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
            {
                tmp[i][j]+=(arr_a[i][k]*arr_b[k][j]);
                tmp[i][j]%=max;
            }
        }
    
    memcpy(res,tmp,sizeof(ll)*4);
    return 0;
}
int dc(ll n, ll arr[][2])
{
    if(n==1)
        return 0;
    
    dc(n/2,arr);

    if(n%2==0)
        multiply(res,res);
    else // b%2==1
    {
        multiply(res,res);
        multiply(res,arr);
    }
    return 0;
}
int main(void)
{
    ll n; scanf("%lld", &n);
    dc(n,arr);
    
    printf("%lld", res[1][0]);
}   