// https://www.acmicpc.net/problem/11066
// 2021-04-01 21:32:04 152ms
#include<iostream>
#include<vector>
using namespace std;
#define min(x,y) ((x)<(y) ? (x):(y))

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<int> arr(n+1);
        vector<int> sum(n+1,0);
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &arr[i]);
            sum[i]=sum[i-1]+arr[i];
        }
        
        vector<vector<int>> memo(n+1, vector<int>(n+1,0));

        for(int r=1; r<=n; r++) // 끝점
            for(int i=1; i+r<=n; i++) // 시작점
            {
                memo[i][i+r]=2000000000; // 대충 최댓값
                for(int mid=i; mid<i+r; mid++) // 구간을 두개로 나눠 최솟값 구하기
                    memo[i][i+r]=min(memo[i][i+r], memo[i][mid]+memo[mid+1][i+r]+sum[i+r]-sum[i-1]);
            }

        printf("%d\n", memo[1][n]);
    }
}