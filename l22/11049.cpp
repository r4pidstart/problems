// https://www.acmicpc.net/problem/11049
// 2021-04-01 22:32:51 68ms
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
#define min(x,y) ((x)<(y) ? (x):(y))

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<pair<int,int>>> size(n+1, vector<pair<int,int>>(n+1)); // 행렬 크기
    for(int i=1; i<=n; i++)
        scanf("%d%d", &size[i][i].first, &size[i][i].second);
    
    vector<vector<int>> memo(n+1,vector<int>(n+1,0)); // 횟수

    for(int r=1; r<n; r++) // 끝점
        for(int i=1; i+r<=n; i++) // 시작점
        {
            memo[i][i+r]=INT_MAX;
            for(int mid=i; mid<i+r; mid++)
            {            
                int tmp=memo[i][mid]+memo[mid+1][i+r]+(size[i][mid].first*size[i][mid].second*size[mid+1][i+r].second);
                if(memo[i][i+r]>tmp)
                {
                    memo[i][i+r]=tmp;
                    size[i][i+r].first=size[i][mid].first;
                    size[i][i+r].second=size[mid+1][i+r].second;
                }
            }
        }

    printf("%d", memo[1][n]);
}