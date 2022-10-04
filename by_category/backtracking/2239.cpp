// https://www.acmicpc.net/problem/2239
// 2022-10-05 02:10:11 392ms
#include"bits/stdc++.h"
using namespace std;

int check(int x, int y, int target, vector<vector<int> >& table)
{
    for(int i=0; i<9; i++)
        if(table[i][y] == target)
            return 0;
    
    for(int i=0; i<9; i++)
        if(table[x][i] == target)
            return 0;
        
    for(int i=x/3*3; i<x/3*3+3; i++)
        for(int j=y/3*3; j<y/3*3+3; j++)
            if(table[i][j] == target)
                return 0;

    return 1;
}

int dfs(int x, int y, vector<vector<int> >& table)
{
    if(y==9)
        return dfs(x+1, 0, table);
    if(x==9)
        return 1;
    if(table[x][y])
        return dfs(x, y+1, table);

    for(int i=1; i<=9; i++)
        if(check(x, y, i, table))
        {
            table[x][y]=i;
            if(dfs(x, y+1, table))
                return 1;
            table[x][y]=0;
        }
    return 0;
}

int main(void)
{
    vector<vector<int> > table(9, vector<int>(9));
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            scanf(" %1d", &table[i][j]);
    dfs(0, 0, table);
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
            printf("%d", table[i][j]);
        printf("\n");
    }
}

/*
    
*/