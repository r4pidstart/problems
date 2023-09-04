// https://www.acmicpc.net/problem/23048
// 2023-09-04 23:54:57
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);

    vector<int> color(n+1), is_prime(n+1, 1);

    is_prime[1]=0;
    color[1]=0;
    
    int color_cnt=1;
    for(int i=2; i<=n; i++)
    {
        if(!is_prime[i]) continue;
        color[i]=color_cnt;
        for(int j=2*i; j<=n; j+=i)
        {
            color[j]=color_cnt;
            is_prime[j]=0;
        }
        color_cnt++;
    }

    printf("%d\n", color_cnt);
    for(int i=1; i<=n; i++)
        printf("%d ", color[i]+1);
}

/*
    
*/