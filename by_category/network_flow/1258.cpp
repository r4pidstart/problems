// https://www.acmicpc.net/problem/1258
//
#include<bits/stdc++.h>
using namespace std;

class mcmf
{
    // O(VEf)
    private:
        struct edge
        {
            int from, to, capacity, cost, flow=0;
            struct edge* reverse_edge;
            edge(int f, int t, int c, int v) : from(f), to(t), capacity(c), cost(v) {}
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
        mcmf(int size)
        {
            graph.assign(size, vector<edge*>());
        }
        void add_edge(int from, int to, int capa, int cost)
        {
            edge *e1=new edge(from, to, capa, cost);
            edge *e2=new edge(to, from, 0, -cost);
            e1->reverse_edge=e2, e2->reverse_edge=e1;
            graph[from].push_back(e1);
            graph[to].push_back(e2);
        }
        pair<int,int> find_flow(int from, int to) // {minimum_cost, maximum_flow}
        {
            pair<int, int> ret={0,0};
            while(true)
            {
                // spfa O(VE)
                vector<int> cost(graph.size(), INT32_MAX/2), in_queue(graph.size());
                vector<edge*> prev(graph.size(), nullptr);
                queue<int> q;
                cost[from]=0, q.push(from);
                
                while(!q.empty())
                {
                    int now=q.front(); q.pop();
                    in_queue[now]=0;

                    for(auto next : graph[now])
                    {
                        if(next->residual() > 0 and cost[next->to] > cost[now]+next->cost)
                        {
                            prev[next->to]=next;
                            cost[next->to]=cost[now]+next->cost;
                            if(!in_queue[next->to])
                                in_queue[next->to]=1, q.push(next->to);
                        }
                    }
                }

                if(prev[to] == nullptr)
                    break;

                int min_flow = INT32_MAX;
                for(int i=to; i!=from; i=prev[i]->from)
                    min_flow=min(min_flow, prev[i]->residual());
                for(int i=to; i!=from; i=prev[i]->from)
                    prev[i]->add_flow(min_flow), ret.first+=min_flow*prev[i]->cost;
                ret.second+=min_flow;
            }
            return ret;
        }
};

int main(void)
{
    int n; scanf("%d", &n);
    mcmf flow(2*n +2);
    int const start = 2*n, end = 2*n + 1;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            int a; scanf("%d", &a);
            flow.add_edge(i, j+n, 1, a);
        }
    for(int i=0; i<n; i++)
    {
        flow.add_edge(start, i, 1, 0);
        flow.add_edge(i+n, end, 1, 0);
    }
    printf("%d", flow.find_flow(start, end).first);
}   

/*
    
*/