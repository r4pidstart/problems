// https://www.acmicpc.net/problem/2917
// 2023-10-05 23:38:13
#include"bits/stdc++.h"
using namespace std;

int decision(pair<int,int>& s, pair<int,int>& e, int mid, 
    vector<vector<char> >& graph, vector<vector<int> >& dist_from_tree)
{
    if(dist_from_tree[s.first][s.second] < mid)
        return 0;
        
    vector<vector<int> > visited(graph.size(), vector<int>(graph[0].size()));
    queue<pair<int,int> > q;
    q.push(s);
    visited[s.first][s.second]=1;

    while(q.size())
    {
        if(q.front() == e)
            return 1;

        auto [x, y]=q.front();
        q.pop();

        const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};     
        for(int w=0; w<4; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(0<=nx and nx<graph.size() and 0<=ny and ny<graph[0].size() and !visited[nx][ny] and dist_from_tree[nx][ny] >= mid)
                visited[nx][ny]=1, q.push({nx, ny});
        }
    }
    return 0;
}  

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<char> > graph(n, vector<char>(m));
    
    pair<int,int> s, e;
    queue<tuple<int, int, int> > tree_q;
    vector<vector<int> > dist_from_tree(n, vector<int>(m, -1));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            scanf(" %c", &graph[i][j]);
            if(graph[i][j]=='+') tree_q.push({i, j, 0}), dist_from_tree[i][j]=0;
            else if(graph[i][j]=='V') s={i, j};
            else if(graph[i][j]=='J') e={i, j};
        }

    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    while(tree_q.size())
    {
        auto [x, y, c]=tree_q.front();
        tree_q.pop();

        for(int w=0; w<4; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(0<=nx and nx<n and 0<=ny and ny<m and dist_from_tree[nx][ny]==-1)
                dist_from_tree[nx][ny]=c+1, tree_q.push({nx, ny, c+1});
        }
    }  
    
#ifdef LOCAL
    printf("\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            printf("%d ", dist_from_tree[i][j]);
        printf("\n");
    }
#endif

    int lo=0, hi=100000, ans=0;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(decision(s, e, mid, graph, dist_from_tree))
            lo=mid+1, ans=mid;
        else
            hi=mid-1;
    }
    printf("%d", ans);
}

/*
    각 칸이 빈 목초지라면 '.', 나무가 있다면 '+', 현재 현우의 위치는 'V', 오두막의 위치는 'J'로 나타나있다.
*/