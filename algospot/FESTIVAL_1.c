// https://algospot.com/judge/problem/read/FESTIVAL
// dp를 이용해 y:빌린 첫 날짜, x:빌린 마지막 날짜를 순차적으로 테이블에 채움
// 2021-03-17 23:50:50 104ms
#include<stdio.h>
#include<string.h>
int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n, l; double min=100;
        scanf("%d %d", &n, &l);
        int memo[n][n], cost[n];

        memset(memo, 0, n*n*sizeof(int));

        for(int i=0; i<n; i++) 
            scanf("%d", &cost[i]);

        for(int i=0; i<n; i++) 
            for(int j=i; j<n; j++)
                memo[0][j]+=cost[i];

        for(int i=l-1; i<n; i++)
        {
            double tmp=(double)memo[0][i]/(i+1);
            if(i+1>=l && min>tmp)
                    min=tmp;
        }

        for(int i=1; i<n; i++)
            for(int j=i; j<n; j++)
            {
                memo[i][j]=memo[i-1][j]-cost[i-1];
                double tmp=(double)memo[i][j]/(j-i+1);
                if(j-i+1>=l && min>tmp)
                    min=tmp;
            }
        printf("%.12f\n", min);
    }
}
