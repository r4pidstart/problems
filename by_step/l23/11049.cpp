// https://www.acmicpc.net/problem/11049
// 2021-04-01 22:32:51 40ms
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
#define min(x,y) ((x)<(y) ? (x):(y))

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,int>> size(n+1);
    for(int i=1; i<=n; i++)
        scanf("%d%d", &size[i].first, &size[i].second);
    
    vector<vector<int>> memo(n+1,vector<int>(n+1,0)); // 횟수

    for(int r=1; r<n; r++) // 끝점
        for(int i=1; i+r<=n; i++) // 시작점
        {
            memo[i][i+r]=INT_MAX;
            for(int mid=i; mid<i+r; mid++)  
                memo[i][i+r]=min(memo[i][i+r],
                                 memo[i][mid]+memo[mid+1][i+r]+(size[i].first*size[mid].second*size[i+r].second));
        }

    printf("%d", memo[1][n]);
}