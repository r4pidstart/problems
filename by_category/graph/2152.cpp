// https://www.acmicpc.net/problem/2152
// 2021-08-08 23:59:47 36ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > graph, scc, sccgraph;
vector<int> finished, visited, sccidx, scc_memo;
stack<int> stk;

int targanDFS(int now)
{
    static int visit_cnt=0, scccnt=0;
    if(visited[now]) return visited[now];
    int low_link=visited[now]=visit_cnt++;
    stk.push(now);

    for(int next : graph[now])
        if(!finished[next])
            low_link=min(low_link, targanDFS(next));
    
    if(visited[now]==low_link)
    {
        vector<int> nowscc;
        while(true)
        {
            int v=stk.top();
            stk.pop();

            sccidx[v]=scccnt;
            finished[v]++;
            nowscc.push_back(v);

            if(now==v) 
                break;
        }
        scc.push_back(nowscc);
        scccnt++;
    }
    return low_link;
}

void dfs(int nowscc, int destscc, int cnt)
{
    if(scc_memo[nowscc] > cnt) return;

    scc_memo[nowscc]=cnt;

    if(destscc==nowscc) return;
    
    for(int nextscc : sccgraph[nowscc])
        if(scc_memo[nextscc] < cnt+scc[nextscc].size())
            dfs(nextscc, destscc, cnt+scc[nextscc].size());
}

int main(void)
{
    int n,m,s,t; scanf("%d%d%d%d", &n,&m,&s,&t);
    finished=visited=sccidx=vector<int>(n,0);
    graph.assign(n, vector<int>());

    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        graph[a-1].push_back(b-1);
    }

    for(int i=0; i<n; i++)
        if(!finished[i])
            targanDFS(i);

    scc_memo.assign(scc.size(), 0);
    sccgraph.assign(scc.size(), vector<int>());

    for(int i=0; i<scc.size(); i++)
    {
        for(int v : scc[i])
            for(int next : graph[v])
                if(i!=sccidx[next])
                    sccgraph[i].push_back(sccidx[next]);
        
        sort(sccgraph[i].begin(), sccgraph[i].end());
        sccgraph[i].erase(unique(sccgraph[i].begin(), sccgraph[i].end()), sccgraph[i].end());
    }

    dfs(sccidx[s-1], sccidx[t-1], scc[sccidx[s-1]].size());
    // bfs
    // queue<pair<int,int> > q;
    // q.push({sccidx[s-1],scc[sccidx[s-1]].size()});

    // while(!q.empty())
    // {
    //     int nowscc=q.front().first, cnt=q.front().second;
    //     q.pop();

    //     if(scc_memo[nowscc] > cnt) continue;
    //     scc_memo[nowscc]=cnt;
    //     if(nowscc==sccidx[t-1]) continue;

    //     for(int nextscc : sccgraph[nowscc])
    //         if(scc_memo[nextscc] < cnt+scc[nextscc].size())
    //             q.push({nextscc, cnt+scc[nextscc].size()});
    // }

    printf("%d", scc_memo[sccidx[t-1]]);
}

/*

*/