// https://www.acmicpc.net/problem/1783
// 2021-11-12 00:31:49 0ms
#include<bits/stdc++.h>
using namespace std;

const int way[4][2]={{2,1}, {1,2}, {-1,2}, {-2,1}};

int n,m; 
int dfs(int x, int y)
{
    int ret=0;
    for(int i=0; i<4; i++)
    {
        int nx=x+way[i][0], ny=y+way[i][1];
        if(0<=nx and nx<min(9,n) and 0<=ny and ny<min(9,m))
            ret=max(ret, 1+dfs(nx, ny));
    }
    return ret;
}

int main(void)
{
    scanf("%d%d", &n,&m);
    vector<vector<int> > table(min(9,n), vector<int>(min(9,m)));
    if(n<3) printf("%d", min(dfs(0,0)+1, 4));
    else printf("%d", max(min(dfs(0,0)+1, 4), m-2));
}

/*
    
*/