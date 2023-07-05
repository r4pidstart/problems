// https://www.acmicpc.net/problem/28276
// 2023-06-29 00:58:43
#include"bits/stdc++.h"
using namespace std;

struct Dsu
{
    vector<vector<pair<int, int> > > parent;
    Dsu(int a, int b)
    {
        parent=vector<vector<pair<int, int> > >(a, vector<pair<int, int> >(b, {-1,0}));
    }
    pair<int,int> find(const pair<int,int>& p)
    {
        int a=p.first, b=p.second;
        if(parent[a][b].first<0)
            return {a,b};
        return parent[a][b]=find({parent[a][b].first, parent[a][b].second});
    }
    int merge(pair<int,int> a, pair<int,int> b)
    {
        a=find({a.first, a.second});
        b=find({b.first, b.second});

        if(a==b)
            return 0;

        if(parent[a.first][a.second].first<parent[b.first][b.second].first) 
            swap(a, b);
        parent[a.first][a.second].first+=parent[b.first][b.second].first;
        parent[b.first][b.second]={a.first, a.second};
        return 1;
    }
};

int make_col_component(vector<vector<int> >& table, Dsu& dsu, int col)
{
    for(int i=0; i<table.size(); i++)
    {
        dsu.parent[i][col]={-1, 0};
        if(i and table[i-1][col] and table[i][col]) dsu.merge({i-1, col}, {i, col});
    }
    return 0;
}

int decision(vector<vector<int> >& table, int mid, int c)
{
    Dsu dsu(table.size(), table[0].size());

    int div_count=0;
    constexpr int mov[2][2]={{-1, 0}, {0, -1}};
    for(int x=0; x<table[0].size(); x++) // 가로기준으로 한 줄씩 봐요
    {
        int max_size=0;
        for(int y=0; y<table.size(); y++)
        {
            if(!table[y][x]) continue;

            for(int m=0; m<2; m++)
            {
                int nx=x+mov[m][0], ny=y+mov[m][1];
                if(0<=nx and nx<table[0].size() and 0<=ny and ny<table.size() and table[ny][nx])
                    dsu.merge({y, x}, {ny, nx});
            }

            auto tmp=dsu.find({y, x});
            max_size=max(max_size, -dsu.parent[tmp.first][tmp.second].first);
        }

        if(max_size > mid)
        {
            // x-1에 칸막이 설치
            div_count++;
            make_col_component(table, dsu, x);
        }
    }
    return div_count<=c;
}

int main(void)
{
#ifdef LOCAL
#endif
    int r,c,w; scanf("%d%d%d", &r, &c, &w);

    vector<vector<int> > table(r, vector<int>(c));
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            scanf("%1d", &table[i][j]);
    
    int max_col_component_size=0;
    for(int x=0; x<table[0].size(); x++)
    {
        int tmp=0;
        for(int y=0; y<table.size(); y++)
        {
            if(table[y][x]) max_col_component_size=max(max_col_component_size, ++tmp);
            else tmp=0;
        }
    }

    int lo=max_col_component_size, hi=r*c, ans=r*c;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(decision(table, mid, w))
            ans=mid, hi=mid-1;
        else
            lo=mid+1;
    }
    printf("%d", ans);
}

/*
    
*/