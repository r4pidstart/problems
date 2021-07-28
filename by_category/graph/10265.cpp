// https://www.acmicpc.net/problem/10265
// 2021-07-28 05:46:24 56ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > graph, scc(1,vector<int>());
vector<int> sccidx, visited, finished, selected; 
stack<int> sccstk;
queue<int> selq;
int scccnt=1;

int targanDFS(int now)
{
    static int visit_cnt=1;
    if(visited[now])
        return visited[now];
    int low_link=visited[now]=visit_cnt++;
    sccstk.push(now);

    for(auto& next : graph[now])
        if(!finished[next])
            low_link=min(low_link, targanDFS(next));
    
    if(low_link==visited[now])
    {
        vector<int> nowscc;
        while(true)
        {
            int v=sccstk.top();
            sccstk.pop();

            finished[v]++;
            sccidx[v]=scccnt;
            nowscc.push_back(v);
            if(v==now)
                break;
        }
        scccnt++;
        scc.push_back(nowscc);
    }
    return low_link;
}

int main(void)
{
    int n, k; scanf("%d%d", &n, &k);
    graph.assign(n+1, vector<int>());
    selected=visited=finished=sccidx=vector<int>(n+1, 0);
    for(int i=1; i<=n; i++)
    {
        int tmp; scanf("%d", &tmp);
        graph[tmp].push_back(i);
        if(tmp==i)
            selq.push(i);
    }

    for(int i=1; i<=n; i++)
        if(!finished[i])
            targanDFS(i);

    // knapsack
    pair<int, bitset<1000> > dp[scc.size()+1][k+1]={};
    for(int i=1; i<=scc.size(); i++)
        for(int j=1; j<=k; j++)
        {
            if(1<scc[i].size() && scc[i].size()<=j)
            {
                if(dp[i-1][j].first < dp[i-1][j-scc[i].size()].first+(int)scc[i].size())
                {
                    dp[i][j].first=dp[i-1][j-scc[i].size()].first+(int)scc[i].size();
                    dp[i][j].second=dp[i-1][j-scc[i].size()].second;
                    dp[i][j].second[i]=1;
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
            else
                dp[i][j]=dp[i-1][j];
        }

    for(int i=1; i<=scc.size(); i++)
        if(dp[scc.size()][k].second[i])
            for(auto& it : scc[i])
                selq.push(it);

    int cnt=0;
    while(!selq.empty())
    {
        int v=selq.front();
        selq.pop();
        if(selected[v])
            continue;
        selected[v]++, cnt++;

        for(auto& i : graph[v])
            selq.push(i);
    }

    if(cnt > k)
        printf("%d", k);
    else
        printf("%d", cnt);
}

/*

*/

