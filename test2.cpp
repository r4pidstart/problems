
#include<iostream>
#include<cstring>
using namespace std;
#define ll long long

ll a,b;
ll arr[5][5];
ll tmp1[5][5];
ll tmp2[5][5];
int flag=0;

int multiply(void)
{
    if(flag==0)
    {
        flag=1;
        memset(tmp1,0,25*sizeof(ll));
        for(int i=0; i<a; i++)
            for(int j=0; j<a; j++)
            {
                for(int k=0; k<a; k++)
                {
                    tmp1[i][j]+=(tmp2[i][k]*tmp2[k][j]);
                    tmp1[i][j]%=1000;
                }
            }
    }
    else
    {
        flag=0;
        memset(tmp2,0,25*sizeof(ll));
        for(int i=0; i<a; i++)
            for(int j=0; j<a; j++)
        {
            for(int k=0; k<a; k++)
            {
                tmp2[i][j]+=(tmp1[i][k]*tmp1[k][j]);
                tmp2[i][j]%=1000;
            }
        }
    }
    return 0;
}

int dc(int a, int b)
{
    if(b==1)
        return 0;

    dc(a,b/2);
    if(b%2==0)
    {
        multiply();
    }
    else // b%2==1
    {
        if(flag==0)
        {
            multiply();
            flag=0;
            memset(tmp2,0,25*sizeof(ll));
            for(int i=0; i<a; i++) // multiply original
                for(int j=0; j<a; j++)
            {
                for(int k=0; k<a; k++)
                {
                    tmp2[i][j]+=(tmp1[i][k]*arr[k][j]);
                    tmp2[i][j]%=1000;
                }
            }
        } 
        else
        {
            multiply();
            flag=1;
            memset(tmp1,0,25*sizeof(ll));
            for(int i=0; i<a; i++) // multiply original 
                for(int j=0; j<a; j++)
            {
                for(int k=0; k<a; k++)
                {
                    tmp1[i][j]+=(tmp2[i][k]*arr[k][j]);
                    tmp1[i][j]%=1000;                
                }
            }
        }
    }
    return 0;
}

int main(void)
{
    scanf("%lld%lld", &a,&b);

    for(int i=0; i<a; i++)
        for(int j=0; j<a; j++)
            scanf("%lld", &arr[i][j]);
    
    memcpy(tmp2, arr, 25*sizeof(ll));
    dc(a,b);

    if(flag==1)
    {
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<a; j++)
                printf("%lld ", tmp1[i][j]%1000);
            printf("\n");
        }    
    }
    else
    {
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<a; j++)
                printf("%lld ", tmp2[i][j]%1000);
            printf("\n");
        }    
    }
}   