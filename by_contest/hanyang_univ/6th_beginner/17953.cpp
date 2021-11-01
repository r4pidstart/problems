// https://www.acmicpc.net/problem/17953
// 2021-10-31 00:57:12 156ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<vector<int> > arr(n+1, vector<int>(m)), dp(n+1, vector<int>(m,0));
    // n번째 날 m번째 음식
    for(int i=0; i<m; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &arr[j][i]);
    
    // dp[i][j] -> i번째 날 m번째 음식을 먹었을 떄의 최대 만족감

    for(int i=1; i<=n; i++) 
        for(int j=0; j<m; j++)
        {
            for(int k=0; k<m; k++) // 전 날 먹은 음식
                if(i!=1 and j==k) dp[i][j]=max(dp[i][j], dp[i-1][k]+(arr[i][j]/2));
                else dp[i][j]=max(dp[i][j], dp[i-1][k]+arr[i][j]);
        }
    printf("%d", *max_element(dp[n].begin(), dp[n].end()));
}

/*
    
*/