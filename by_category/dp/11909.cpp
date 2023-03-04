// https://www.acmicpc.net/problem/11909
// 2023-03-04 18:01:56
#include"bits/stdc++.h"
using namespace std;

int solution(int x, int y, vector<vector<int> >& table)
{
    static vector<vector<int> > dp(table.size(), vector<int>(table.size(), -1));

    if(x==table.size()-1 and y==table.size()-1) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    
    int ret=INT32_MAX;
    if(x!=table.size()-1)
        ret=min(ret, solution(x+1, y, table)+(table[x][y]<=table[x+1][y] ? table[x+1][y]-table[x][y]+1:0));
    if(y!=table.size()-1)
        ret=min(ret, solution(x, y+1, table)+(table[x][y]<=table[x][y+1] ? table[x][y+1]-table[x][y]+1:0));
    
    return dp[x][y]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<vector<int> > table(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &table[i][j]);
    printf("%d", solution(0, 0, table));
}

/*
    
*/