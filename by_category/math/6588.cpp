// https://www.acmicpc.net/problem/6588
// 2021-12-07 00:34:45 32ms
#include<bits/stdc++.h>
using namespace std;

vector<int> prime_table(1000001, 1);

int main(void)
{
    prime_table[1]=0;
    for(int i=2, l=sqrt(1000000); i<=l; i++)
        if(prime_table[i])
            for(int j=i+i; j<=1000000; j+=i)
                prime_table[j]=0;

    int n;
    while(scanf("%d", &n), n!=0)
    {
        int flag=0;
        for(int i=1; i<=n/2; i++)
        {
            if(prime_table[i] and prime_table[n-i])
            {
                printf("%d = %d + %d\n", n, i, n-i);
                flag=1;
                break;
            }
        }
        if(!flag) printf("Goldbach's conjecture is wrong.\n");
    }
}

/*
    
*/