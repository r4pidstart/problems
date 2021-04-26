// https://www.acmicpc.net/problem/12852
// 2021-04-26 16:58:15 8ms
#include<bits/stdc++.h>
using namespace std;

vector<int> memo (1000002, INT32_MAX), route(1000002, 0);

int main(void)
{
    int n; scanf("%d", &n);
    memo[1]=0;
    for(int i=2; i<=n; i++)
    {
        if(i%2==0 && memo[i] > memo[i/2]+1)
        {
                route[i]=i/2;
                memo[i]=memo[i/2]+1;
        }

        if(i%3==0 && memo[i] > memo[i/3]+1)
        {
                route[i]=i/3;
                memo[i]=memo[i/3]+1;
        }

        if(memo[i] > memo[i-1]+1)
        {
            route[i]=i-1;
            memo[i]=memo[i-1]+1;
        }    
    }

    int target=n;
    printf("%d\n", memo[n]);
    while(target!=1)
    {
        printf("%d ", target);
        target=route[target];
    }
    printf("%d", target);
    return 0;
}