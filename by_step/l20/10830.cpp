// https://www.acmicpc.net/problem/10830
// 2021-03-23 03:20:31 0ms
#include<iostream>
#include<cstring>
using namespace std;
#define ll long long

ll arr[5][5], res[5][5];
ll a,b;

int multiply(ll arr_a[][5], ll arr_b[][5])
{
    ll tmp[5][5]={};
    for(int i=0; i<a; i++)
        for(int j=0; j<a; j++)
        {
            for(int k=0; k<a; k++)
            {
                tmp[i][j]+=(arr_a[i][k]*arr_b[k][j]);
                tmp[i][j]%=1000;
            }
        }
    
    memcpy(res,tmp,sizeof(ll)*25);
    return 0;
}
int dc(ll a, ll b, ll arr[][5])
{
    if(b==1)
        return 0;
    
    dc(a,b/2,arr);

    if(b%2==0)
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
    scanf("%lld%lld", &a,&b);
    for(int i=0; i<a; i++)
        for(int j=0; j<a; j++)
            scanf("%lld", &arr[i][j]);

    memcpy(res,arr,sizeof(ll)*25);
    dc(a,b,arr);
    
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<a; j++)
            printf("%lld ", res[i][j]%1000);
        printf("\n");
    }
}   