// https://www.acmicpc.net/problem/3933
// 2023-03-05 19:17:12
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    vector<vector<int> > dp((1<<15)+1, vector<int>(5));
    dp[0][0]=1;
    for(int k=1; k*k<=1<<15; k++)
        for(int i=1; i<=1<<15; i++)
            for(int j=1; j<=4; j++)
                if(i-k*k>=0)
                    dp[i][j]+=dp[i-k*k][j-1];

    int a; scanf("%d", &a);
    while(a)
    {
        printf("%d\n", accumulate(dp[a].begin(), dp[a].end(), 0));
        scanf("%d", &a);
    }
}

/*
    
*/