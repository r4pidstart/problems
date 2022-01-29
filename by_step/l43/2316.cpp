// https://www.acmicpc.net/problem/2316
// 2022-01-30 04:50:24 12ms
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
    int n,p; scanf("%d%d", &n,&p);
    network_flow flow(n+n+1);
    for(int i=1; i<=n; i++)
        flow.add_edge(i, i+n, 1);
    for(int i=0; i<p; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        flow.add_edge(a+n, b, 1);
        flow.add_edge(b+n, a, 1);
    }
    printf("%d", flow.find_flow(1+n, 2));
}

/*
    
*/