// https://www.acmicpc.net/problem/1143
// 2022-01-15 04:08:30 8ms
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
                    for(int next : graph[v])
                        possible_route.push_back(next);

                    if(v==now) break;
                }
                sccarr.push_back(component);
                this->graph.push_back(possible_route);
            }
            return low_link;
        }

    public:
        vector<vector<int> > sccarr, graph;
        vector<int> sccidx;

        SCC(const vector<vector<int> >& graph)
        {
            int n=graph.size();
            finished.assign(n,0), visited.assign(n,0), sccidx.assign(n,-1);

            for(int i=1; i<graph.size(); i++)
                if(!visited[i]) tarjanDFS(i, graph);

            for(int i=0; i<this->graph.size(); i++)
            {
                auto& it = this->graph[i];
                for(auto& j : it) j=sccidx[j];

                sort(it.begin(), it.end());
                it.resize(unique(it.begin(), it.end())-it.begin());

                auto self_cycle=find(it.begin(), it.end(), i);
                if(self_cycle != it.end()) it.erase(self_cycle);
            }
        }
};

void office_build(int now, const SCC scc, vector<int>& p_component, vector<int>& p_town, const vector<vector<int> >& parents, const vector<int>& cost)
{
    if(!p_component[now]) // 현재 컴포넌트에 도달할 수 있는 경찰서가 없는 경우
    {
        for(int next : parents[now])
            office_build(next, scc, p_component, p_town, parents, cost);
        p_component[now]=1;
        if(!parents[now].size())
        {
            int target, price=10000;
            for(int j : scc.sccarr[now])
            {
                if(price>cost[j])
                    price=cost[j], target=j;
            }
            p_town[target]=1;
        }
    }
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> cost(n+1);
    for(int i=1; i<=n; i++)
        scanf("%d", &cost[i]);
    
    vector<vector<int> > graph(n+1);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            char c; scanf(" %c", &c);
            if(c=='Y') graph[i].push_back(j);
        }
    SCC scc(graph);
    vector<int> p_component(scc.sccarr.size(),0), p_town(n+1, 0);
    
    vector<vector<int> > parents(scc.sccarr.size());
    for(int i=0; i<scc.sccarr.size(); i++)
    {
        for(int dest : scc.graph[i])
            parents[dest].push_back(i);
    }

    // 필수로 지어야 하는 경찰서를 모두 짓기
    for(int i=0; i<scc.sccarr.size(); i++)
        office_build(i, scc, p_component, p_town, parents, cost);

    // 평균 대충 미리 구하기
    int sum=0, cnt=0;
    for(int i=1; i<=n; i++)
        if(p_town[i]) cnt++, sum+=cost[i];
    
    double tmp_avg=(double)sum/cnt;

    // 작은 것 부터 더하면서 avg 최소로 갱신
    vector<pair<int,int> > cost_pair;
    for(int i=1; i<=n; i++) cost_pair.push_back({cost[i], i});
    sort(cost_pair.begin(), cost_pair.end());

    for(int i=0; i<n; i++)
    {
        if(!p_town[cost_pair[i].second])
        {
            int tmpsum=sum+=cost[cost_pair[i].second];
            if((double)tmpsum/(cnt+1) < tmp_avg)
            {
                sum=tmpsum, cnt++;
                tmp_avg=(double)sum/cnt;
            }
        }
    }

    printf("%.10lf", tmp_avg);
}

/*
    
*/