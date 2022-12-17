// http://220.89.64.243/30stair/jumping_cow/jumping_cow.php?pname=jumping_cow
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<vector<int> > dp(2, vector<int>(n+1, 0));
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    dp[1][0]=0;
    for(int j=1; j<=n; j++)
    {
        dp[0][j]=max(dp[1][j-1] - arr[j-1], dp[0][j-1]);
        dp[1][j]=max(dp[0][j-1] + arr[j-1], dp[1][j-1]);
    }
    
    printf("%d", max(dp[0][n], dp[1][n]));
}

/*
    
*/