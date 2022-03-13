// https://www.acmicpc.net/problem/1420
// 2022-03-14 01:59:16 4ms
#include<bits/stdc++.h>
using namespace std;

class network_flow
{
    // edmonds-karp O(VE^2)
    private:
        struct edge
        {
            int from, to, capacity, flow=0;
            edge* reverse_edge=nullptr;
            edge(int f, int t, int c) : from(f), to(t), capacity(c) {}
            inline int residual(void)
            {
                return capacity-flow;
            }
            inline void add_flow(int amount)
            {
                flow+=amount;
                reverse_edge->flow-=amount;
            }
        };
        vector<vector<edge*> > graph;
    public:
        network_flow(int size)
        {
            graph.assign(size, vector<edge*>());
        }
        void add_edge(int from, int to, int capa)
        {
            edge* e1=new edge(from, to, capa);
            edge* e2=new edge(to, from, 0);
            e1->reverse_edge=e2, e2->reverse_edge=e1;
            graph[from].push_back(e1);
            graph[to].push_back(e2);
        }
        int find_flow(int from, int to)
        {
            int ret=0;
            while(true)
            {
                queue<int> q;
                vector<edge*> prev(graph.size(), nullptr);
                q.push(from);
                while(!q.empty() and !prev[to])
                {
                    int now=q.front(); q.pop();
                    for(edge* next : graph[now])
                        if(!prev[next->to] and next->residual())
                            q.push(next->to), prev[next->to]=next;
                }
                if(!prev[to]) break;

                int min_flow=INT32_MAX;
                for(int i=to; i!=from; i=prev[i]->from)
                    min_flow=min(min_flow, prev[i]->residual());
                for(int i=to; i!=from; i=prev[i]->from)
                    prev[i]->add_flow(min_flow);
                ret+=min_flow;
            }
            return ret;
        }
};

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<char> > table(n, vector<char>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" %c", &table[i][j]);

    network_flow flow(2*n*m);
    int s,e;

    // 간선을 막는 것이 아니라 정점을 막는 것이므로, 벽이 될 수 있는 정점을 만들기
    vector<int> could_be_wall(2*n*m, 0);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(table[i][j] == 'K') s=(i*m + j) * 2;
            if(table[i][j] == 'H') e=(i*m + j) * 2;

            if(table[i][j] == '.')
                could_be_wall[(i*m + j) * 2]=1, flow.add_edge((i*m + j) * 2, (i*m + j) * 2 + 1, 1);
        }

    const int mov[4][2]={{0,1}, {1,0}, {-1,0}, {0,-1}};
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            int now=(i*m + j)*2;
            if(could_be_wall[now]) now++;
            for(int w=0; w<4; w++)
            {
                int nx=i+mov[w][0], ny=j+mov[w][1];
                if(0<=nx and nx<n and 0<=ny and ny<m and table[nx][ny] != '#')
                    flow.add_edge(now, (nx*m + ny)*2, INT32_MAX/2);
            }
        }

    int ans=flow.find_flow(s, e);
    printf("%d", ans>100000 ? -1:ans);
}

/*
    
*/