// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

class SCC
{
    // vector<vector<int> > graph(n+1)
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

int main(void)
{
#ifdef LOCAL
#endif
	int n,m; scanf("%d%d", &n, &m);
	vector<vector<int> > graph(n+1);
	for(int i=0; i<m; i++)
	{
		int a,b; scanf("%d%d", &a, &b);
		graph[a].push_back(b);
	}

	SCC scc(graph);
	if(scc.sccarr.size()==1)
		printf("Yes");
	else
		printf("No");
	// queue<int> q;
	// q.push(scc.graph.size()-1);
	// vector<int> visited(scc.graph.size());
	// visited[scc.graph.size()-1]=1;

	// while(q.size())
	// {
	// 	int now=q.front();
	// 	q.pop();
		
	// 	if(scc.graph[now].size() > 1)
	// 		return !printf("0");
			
	// 	for(auto next : scc.graph[now])
	// 	{
	// 		q.push(next);
	// 		visited[next]=1;
	// 	}	
	// }

	// for(int i=0; i<scc.graph.size(); i++)
	// 	if(!visited[i])
	// 		return !printf("0");
		
	// printf("%d\n", scc.sccarr[scc.graph.size()-1].size());
	// sort(scc.sccarr[scc.graph.size()-1].begin(), scc.sccarr[scc.graph.size()-1].end());
	// for(auto it : scc.sccarr[scc.graph.size()-1])
	// 	printf("%d ", it);
}

/*
	
*/