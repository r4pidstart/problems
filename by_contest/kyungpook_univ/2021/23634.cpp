// https://www.acmicpc.net/problem/23634
// 2021-11-26 12:38:46 1076ms
#include<bits/stdc++.h>
using namespace std;

const int way[4][2]={{0,1}, {1,0}, {-1,0}, {0,-1}};
vector<int> parent;
vector<vector<int> > table, fireIdx;

int find(int a)
{   
    if(parent[a]<0)
        return a;
    return parent[a]=find(parent[a]);
}

int merge(int a, int b)
{
    a=find(a), b=find(b);
    if(a==b) return 1;

    if(parent[a]>parent[b])
        swap(a,b);

    parent[a]+=parent[b];
    parent[b]=a;
    return 0;
}

int fireCnt=0;
void dfs(int x, int y)
{
    fireIdx[x][y]=fireCnt;
    for(int i=0; i<4; i++)
    {
        int nx=x+way[i][0], ny=y+way[i][1];
        if(0<=nx and nx<table.size() and 0<=ny and ny<table[0].size() and table[nx][ny]==0 and !fireIdx[nx][ny])
            dfs(nx, ny);
    }
}

struct Status
{
    int t, x, y;
};

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    table.assign(n,vector<int>(m));
    fireIdx.assign(n,vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d", &table[i][j]);
    
    // 각 불의 번호를 구하기
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(!fireIdx[i][j] and table[i][j]==0)
                fireCnt++, dfs(i,j);

    parent.assign(fireCnt+1, -1);

    if(fireCnt==0) return !printf("%d %d", 0,0);

    queue<Status> q; 
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(table[i][j]==0) q.push({0,i,j});

    // 시간별로 불의 갯수와, 불의 크기를 기록
    vector<pair<int, pair<int,int> > > cand;
    vector<vector<int> > visited(n,vector<int>(m,0));
    int prev=0, visitCnt=0, cnt=fireCnt;
    while(!q.empty())
    {
        auto now=q.front(); q.pop();
        // 시간 단위가 끝날 때 마다 불의 갯수 체크 
        if(prev != now.t)
            prev=now.t, cand.push_back({cnt, {now.t-1, visitCnt}});

        if(visited[now.x][now.y]) continue;
        visitCnt+=visited[now.x][now.y]=1;
        
        // 불이 퍼질 때 마다 주변 불을 체크
        if(!fireIdx[now.x][now.y])
        {
            vector<int> adj;
            for(int i=0; i<4; i++)
            {
                int nx=now.x+way[i][0], ny=now.y+way[i][1];
                if(0<=nx and nx<table.size() and 0<=ny and ny<table[0].size())
                    if(fireIdx[nx][ny]!=0) adj.push_back(fireIdx[nx][ny]);
            }
            for(int i=0; i<(int)adj.size()-1; i++)
                if(merge(adj[i], adj[i+1]) == 0) 
                    cnt--;
            fireIdx[now.x][now.y]=adj[0];
        }
            

        for(int i=0; i<4; i++)
        {
            int nx=now.x+way[i][0], ny=now.y+way[i][1];
            if(0<=nx and nx<table.size() and 0<=ny and ny<table[0].size())
                if(table[nx][ny]==1) q.push({now.t+1, nx, ny});
        }
    }
    cand.push_back({cnt, {prev, visitCnt}});
    
    // c와 t가 작은 순으로 정렬
    sort(cand.begin(), cand.end());
    printf("%d %d", cand[0].second.first, cand[0].second.second);
}

/*
    
*/