// https://www.acmicpc.net/problem/4883
// 2021-09-15 01:28:52 60ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t=0;
    const int w[4][2]={{0,1}, {1,0}, {1,-1}, {1,1}};
    while(++t)
    {
        int n; scanf("%d", &n);
        if(n==0) break;
        vector<vector<int> > graph(n, vector<int>(3)), dp(n, vector<int>(3,INT32_MAX/2));
        for(int i=0; i<n; i++)
            for(int j=0; j<3; j++)
                scanf("%d", &graph[i][j]);

        dp[0][1]=graph[0][1];
        for(int i=0; i<n; i++)
            for(int j=0; j<3; j++)
                for(int k=0; k<4; k++)
                {
                    int nx=i+w[k][0], ny=j+w[k][1];
                    if(0<=nx && nx<n && 0<=ny && ny<3)
                        dp[nx][ny]=min(dp[nx][ny], dp[i][j]+graph[nx][ny]);
                }
        printf("%d. %d\n", t, dp[n-1][1]);
    }
}

/*

*/