// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

// vector<vector<int> > graph(n+1)
class SCC
{
    private:
        vector<int> finished, visited;
        stack<int> stk;
        int visit_cnt=0;

        int tarjanDFS(int now, const vector<vector<int> >& graph)
        {
            if(visited[now]) return visited[now];
            int low_link=visited[now]=++visit_cnt;
            stk.push(now);

            for(int next : graph[now])
                if(!finished[next]) low_link=min(low_link, tarjanDFS(next, graph));

            if(low_link==visited[now])
            {
                vector<int> component, possible_route;
                int idx=sccarr.size();
                while(true)
                {
                    int v=stk.top(); stk.pop();

                    finished[v]=1;
                    sccidx[v]=idx;
                    component.push_back(v);

                    //
                    for(int next : graph[v])
                        possible_route.push_back(next);
                    //

                    if(v==now) break;
                }
                sccarr.push_back(component);

                //
                this->graph.push_back(possible_route);
                //
            }
            return low_link;
        }

    public:
        vector<vector<int> > sccarr;
        vector<int> sccidx;
        vector<vector<int> > graph;

        SCC(const vector<vector<int> >& graph)
        {
            const int n=graph.size();
            finished.assign(n,0), visited.assign(n,0), sccidx.assign(n,-1);

            for(int i=1; i<graph.size(); i++)
                if(!visited[i]) tarjanDFS(i, graph);

            //
            for(auto& it : this->graph)
            {
                for(auto& i : it)
                    i=sccidx[i];
                it.resize(unique(it.begin(), it.end())-it.begin());
            }
            //
        }
};

vector<int> memo;
int dp(int now, const vector<vector<int> >& graph, const SCC& scc)
{
    if(memo[now]) return memo[now];
    
    int component_size=scc.sccarr[now].size();
    int& ret=memo[now]=component_size;
    for(int next : graph[now])
        if(now != next)
            ret=max(ret, component_size+dp(next, graph, scc));
    return ret;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > graph(n+1);
    for(int i=1; i<=n; i++)
    {
        int d; scanf("%d", &d);
        if(i+d<=n) graph[i].push_back(i+d);
        if(i-d>=1) graph[i].push_back(i-d);
    }

    int s; scanf("%d", &s);
    SCC scc(graph);

    // scc를 구한 후, 그래프로 만들어서, dp로 갈 수 있는 정점의 개수를 탐색?
    memo.assign(scc.sccarr.size(), 0);
    printf("%d", dp(scc.sccidx[s], scc.graph, scc));
    return 0;
}

/*
    
*/