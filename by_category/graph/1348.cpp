// https://www.acmicpc.net/problem/1348
// 2022-03-29 21:32:38 204ms
#include<bits/stdc++.h>
using namespace std;

class bipartite_matching
{
    // O(VE)
    public:
        vector<vector<int> > graph;
        vector<int> btoa, visited;
        int visit_cnt=0;
        bool make_match(int now)
        {
            visited[now]=visit_cnt;
            for(int next : graph[now])
                if(btoa[next] == -1 or (visited[btoa[next]] != visit_cnt and make_match(btoa[next])))
                {
                    btoa[next]=now;
                    return 1;
                }
            return 0;
        }
        bipartite_matching(int sizeA, int sizeB)
        {
            graph.assign(sizeA, vector<int>());
            btoa.assign(sizeB, -1);
            visited.assign(sizeA, 0);
        }
        inline void add_edge(int fromA, int toB)
        {
            graph[fromA].push_back(toB);
        }
        int find_match(void) 
        {
            int match=0;
            for(int i=0; i<graph.size(); i++)
            {
                visit_cnt++;
                if(make_match(i)) match++;
            }
            return match;
        }
};

int decision(int n, int m, int mid, vector<vector<char> >& table, vector<pair<int,int> >& car, bipartite_matching& bi)
{
    const int mov[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0}};
    bi.btoa.assign(10000, -1);
    bi.graph.assign(10000, vector<int>());
    for(auto it : car)
    {
        // 구역 번호 : i*m + j
        vector<vector<int> > visited(n, vector<int>(m));
        queue<pair<int,pair<int,int> > > q;
        q.push({0, it});
        while(q.size())
        {
            int now_time=q.front().first;
            auto now=q.front().second;
            q.pop();

            if(now_time > mid) break;
            if(visited[now.first][now.second]) continue;
            visited[now.first][now.second] = 1;

            if(table[now.first][now.second] == 'P') 
                bi.add_edge(it.first*m + it.second, now.first*m + now.second);
            
            for(int w=0; w<4; w++)
            {
                int nx=now.first+mov[w][0], ny=now.second+mov[w][1];
                if(0<=nx and nx<n and 0<=ny and ny<m and table[nx][ny]!='X')
                    q.push({now_time+1, {nx, ny}});
            }
        } 
    }
    return (bi.find_match() == car.size());
}

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<pair<int,int> > car;
    vector<vector<char> > table(n, vector<char>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            scanf(" %c", &table[i][j]);
            if(table[i][j] == 'C') car.push_back({i,j});
        }
    if(!car.size())
        return !printf("0");

    bipartite_matching bi(10000, 10000);

    int lo=-1, hi=10000, ans=-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(decision(n,m, mid, table, car, bi))
            ans=mid, hi=mid-1;
        else
            lo=mid+1;
    }
    printf("%d", ans);
}

/*
    6 11 
    XXXXXXXXXXX
    X......XPPX
    XC...P.XPPX
    X....C.X..X
    X....C....X
    XXXXXXXXXXX

    -> 6
*/