// https://algospot.com/judge/problem/read/FESTIVAL
// 테이블을 모두 채우지 않고, a~b일간의 비용을 memo[b]-memo[a-1]로 바로 구함
// 2021-03-18 18:56:35 40ms 
#include<stdio.h>
#define min(x,y) ((x)<(y) ? (x):(y))
int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n, l; double res=100;
        scanf("%d %d", &n, &l);
        int memo[n+1], cost[n+1];

        for(int i=0; i<n; i++) 
            scanf("%d", &cost[i+1]);

        memo[0]=0;
        for(int i=0; i<n; i++)
            memo[i+1]=memo[i]+cost[i+1];

        for(int i=l; i<=n; i++)
            for(int j=0; j<=i-l; j++)
                res=min(res, (double)(memo[i]-memo[j])/(i-j));

        printf("%.12f\n", res);
    }
}
