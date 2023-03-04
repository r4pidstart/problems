// https://www.acmicpc.net/problem/3114
// 2023-03-04 18:46:31
#include"bits/stdc++.h"
using namespace std;

int get_sum(int x, int y, int a, int b, vector<vector<int> >& table)
{
    if(!x or !y or !a or !b) return 0;
    return table[a][b]-table[x-1][b]-table[a][y-1]+table[x-1][y-1];
}

int solution(int x, int y, vector<vector<int> >& p_apple, vector<vector<int> >& p_banana)
{
    static vector<vector<int> > dp(p_apple.size(), vector<int>(p_apple[0].size(), -1));

    if(x==p_apple.size()-1 and y==p_apple[0].size()-1) return 0;    
    if(dp[x][y] != -1) return dp[x][y];
    
    int ret=0;
    if(y!=p_apple[0].size()-1)
        ret=max(ret, solution(x, y+1, p_apple, p_banana)+get_sum(1, y+1, x-1, y+1, p_banana));    
    if(x!=p_apple.size()-1)
        ret=max(ret, solution(x+1, y, p_apple, p_banana)+get_sum(x+1, 1, x+1, y-1, p_apple));
    if(x!=p_apple.size()-1 and y!=p_apple[0].size()-1)
        ret=max(ret, solution(x+1, y+1, p_apple, p_banana)
            +get_sum(x+1, 1, x+1, y, p_apple)+get_sum(1, y+1, x, y+1, p_banana));
    
    return dp[x][y]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > apple(n+1, vector<int>(m+1)), banana(n+1, vector<int>(m+1));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            char a; int b; scanf(" %c%d", &a, &b);
            if(a=='A') apple[i][j]=b;
            else banana[i][j]=b;
        }
    
    vector<vector<int> > psum_apple(n+1, vector<int>(m+1)), psum_banana(n+1, vector<int>(m+1));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            psum_apple[i][j]=psum_apple[i-1][j]+psum_apple[i][j-1]-psum_apple[i-1][j-1]+apple[i][j];
            psum_banana[i][j]=psum_banana[i-1][j]+psum_banana[i][j-1]-psum_banana[i-1][j-1]+banana[i][j];
        }
    
    printf("%d", solution(1, 1, psum_apple, psum_banana));
}

/*
    
*/