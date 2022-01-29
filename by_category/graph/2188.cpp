// https://www.acmicpc.net/problem/2188
// 2022-01-30 03:40:50 8ms
#include<bits/stdc++.h>
using namespace std;

class network_flow
{
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
    int n,m; scanf("%d%d", &n,&m);
    network_flow flow(n+m+2);
    for(int i=0; i<n; i++)
        flow.add_edge(0, i+1, 1);
    for(int i=0; i<m; i++)
        flow.add_edge(i+n+1, n+m+1, 1);

    for(int i=0; i<n; i++)
    {
        int c; scanf("%d", &c);
        while(c--)
        {
            int num; scanf("%d", &num);
            flow.add_edge(i+1, num+n, 1);
        }
    }
    
    printf("%d", flow.find_flow(0, n+m+1));
}

/*
    
*/