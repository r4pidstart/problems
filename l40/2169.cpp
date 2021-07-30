// https://www.acmicpc.net/problem/2169
// 2021-07-30 06:15:27 140ms 
#include<bits/stdc++.h>
using namespace std;

const int w[3][2]={{0,1}, {0,-1}, {1,0}};
int n, m;

int main(void)
{
    vector<vector<int> > field, memo[3];
    scanf("%d%d", &n,&m);
    field.assign(n,vector<int>(m,0));
    for(int i=0; i<3; i++)
        memo[i].assign(n,vector<int>(m, INT32_MIN/2));  
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &field[i][j]);
    memo[2][0][0]=field[0][0];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++) // -> (0)
        {
            if(i!=0) 
                memo[2][i][j]=max({memo[2][i][j], memo[0][i-1][j]+field[i][j], 
                                   memo[1][i-1][j]+field[i][j], memo[2][i-1][j]+field[i][j]});
            if(j!=0)
                memo[0][i][j]=max({memo[0][i][j], memo[0][i][j-1]+field[i][j],
                                   memo[2][i][j-1]+field[i][j]});
        }
        if(i!=0)
            for(int j=m-1; j>=0; j--) // <- (1)
            {
                if(i!=0) 
                    memo[2][i][j]=max({memo[2][i][j], memo[0][i-1][j]+field[i][j], 
                                    memo[1][i-1][j]+field[i][j], memo[2][i-1][j]+field[i][j]});
                if(j!=0)
                    memo[0][i][j]=max({memo[0][i][j], memo[0][i][j-1]+field[i][j],
                                    memo[2][i][j-1]+field[i][j]});
                if(j!=m-1)
                    memo[1][i][j]=max({memo[1][i][j], memo[1][i][j+1]+field[i][j],
                                    memo[2][i][j+1]+field[i][j]});
            }
    }
    printf("%d", max({memo[0][n-1][m-1], memo[1][n-1][m-1], memo[2][n-1][m-1]}));
}

/*

*/
