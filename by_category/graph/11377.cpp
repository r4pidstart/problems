// https://www.acmicpc.net/problem/
//
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
    int n,m,k; scanf("%d%d%d", &n,&m,&k);
    network_flow flow(n+m+3);
    // start: 0, bridge: n+m+1, end: n+m+2

    for(int i=1; i<=n; i++) // start to each people
        flow.add_edge(0, i, 1);
    for(int i=1; i<=n; i++) // bridge to each people
        flow.add_edge(n+m+1, i, 1);
    for(int i=1; i<=m; i++) // each works to end
        flow.add_edge(n+i, n+m+2, 1);
        
    flow.add_edge(0, n+m+1, k);
    
    for(int i=1; i<=n; i++)
    {
        int cnt; scanf("%d", &cnt);
        while(cnt--)
        {
            int work_num; scanf("%d", &work_num);
            flow.add_edge(i, work_num+n, 1);
        }
    }
    
    printf("%d", flow.find_flow(0, n+m+2));
}

/*
    
*/