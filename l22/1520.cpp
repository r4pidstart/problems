// https://www.acmicpc.net/problem/1520
// 2021-03-31 00:49:13 36ms
#include<iostream>
#include<vector>
using namespace std;

int dp(int x, int y, int end_x, int end_y, vector<vector<int>> &map, vector<vector<int>> &memo)
{
    if(x==end_x && y==end_y) // 도착
        return 1;

    if(memo[x][y]!=-1) // 탐색 여부 확인
        return memo[x][y];
    
    memo[x][y]=0; 

    if(x!=0) // 맨 윗 줄이 아닐때
    {
        if(map[x-1][y]<map[x][y])
            memo[x][y]+=dp(x-1,y, end_x,end_y, map, memo);
    }

    if(x!=end_x) // 맨 아랫 줄이 아닐때
    {
        if(map[x+1][y]<map[x][y])
            memo[x][y]+=dp(x+1,y, end_x,end_y, map, memo);
    }

    if(y!=0) // 맨 왼쪽 줄이 아닐때
    {
        if(map[x][y-1]<map[x][y])
            memo[x][y]+=dp(x,y-1, end_x,end_y, map, memo);
    }

    if(y!=end_y) // 맨 오른쪽 줄이 아닐때
    {
        if(map[x][y+1]<map[x][y])
            memo[x][y]+=dp(x,y+1, end_x,end_y, map, memo);
    }

    return memo[x][y];
}

int main(void)
{
    int n,m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> map(n,vector<int> (m));
    vector<vector<int>> memo(n,vector<int> (m,-1));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &map[i][j]);
    dp(0,0, n-1,m-1, map, memo);

    printf("%d", memo[0][0]);
}