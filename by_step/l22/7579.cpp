// https://www.acmicpc.net/problem/7579
// 2021-04-07 02:47:11 0ms
#include<iostream>
#include<vector>
using namespace std;
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<pair<int,int>> arr(n+1);
    int sum_value=0;
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i].first);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &arr[i].second);
        sum_value+=arr[i].second;
    }    

    int memo[n+1][sum_value+1]={}, min=2100000000;
    // 특정 가치를 소모해 얻을 수 있는 최대의 메모리
    for(int i=1; i<=n; i++)
        for(int j=0; j<=sum_value; j++) 
        {
            if(arr[i].second>j)
                memo[i][j]=memo[i-1][j];
            else
            {
                memo[i][j]=max(memo[i-1][j], memo[i-1][j-arr[i].second]+arr[i].first);
                if(memo[i][j]>=m)
                    min=min(min,j);
            }
        }
    printf("%d", min);
    return 0;
}