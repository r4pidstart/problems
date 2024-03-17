// https://www.acmicpc.net/problem/15711
// 2024-03-14 20:39:38
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    vector<int> prime_table(4e6+1, 1);
    vector<int> primes;
    prime_table[0]=prime_table[1]=0;
    for(int i=2; i<prime_table.size(); i++)
        if(prime_table[i])
        {
            primes.push_back(i);
            for(int j=i+i; j<prime_table.size(); j+=i)
                prime_table[j]=0;
        }
    
#ifdef LOCAL
    printf("%d\n", accumulate(prime_table.begin(), prime_table.end(), 0));
#endif

    while(t--)
    {
        long a,b; scanf("%ld%ld", &a, &b);
        if((a+b)%2==0)
            printf("YES\n");
        else
        {
            int flag=0;
            for(int i : primes)
                if(i!=(a+b-2) and (a+b-2)%i==0) 
                    flag=1;
            printf("%s\n", flag ? "NO":"YES");
        }
    }
}

/*
    
*/