// https://www.acmicpc.net/problem/1941
// 2024-03-12 20:28:54
#include"bits/stdc++.h"
using namespace std;

pair<int, int> dfs(int x, int y, const vector<vector<char> >& table, vector<vector<int> >& selected)
{
    selected[x][y]=0;

    pair<int, int> ret={1, table[x][y]=='S'};

    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    for(int w=0; w<4; w++)
    {
        int nx=x+way[w][0], ny=y+way[w][1];
        if(0<=nx and nx<5 and 0<=ny and ny<5 and selected[nx][ny])
        {
            auto tmp=dfs(nx, ny, table, selected);
            ret.first+=tmp.first, ret.second+=tmp.second;
        }
    }
    return ret;
}

int check(const vector<vector<char> >& table, const vector<int>& combi)
{
    vector<vector<int> > selected(5, vector<int>(5));
    int x,y;
    for(int i=0; i<25; i++)
        if(combi[i])
            selected[i/5][i%5]=1, x=i/5, y=i%5;
    
    auto cnt=dfs(x, y, table, selected);
    return cnt.first==7 and cnt.second >= 4;
}

int main(void)
{
    vector<vector<char> > table(5, vector<char>(5));
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            scanf(" %c", &table[i][j]);
    
    int ans=0;
    vector<int> combi(25);
    fill(combi.begin(), combi.begin()+7, 1);
    do
    {  
        ans+=check(table, combi); 
    }
    while(prev_permutation(combi.begin(), combi.end()));
    printf("%d", ans);
}

/*
    
*/