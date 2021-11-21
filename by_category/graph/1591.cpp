// https://www.acmicpc.net/problem/1591
// 2021-11-22 05:27:09 48ms
#include<bits/stdc++.h>
using namespace std;

map<vector<int>, int> idx;
vector<int> indegree(1001), outdegree(1001);
vector<vector<int> > graph(1001, vector<int>(1001)), edge(1001);

stack<int> stk;

void dfs(int start)
{
    if(outdegree[start]==0)
    {
        for(int i=edge[start].size()-1; i>=0; i--)
            stk.push(edge[start][i]);
        return;
    }

    for(int i=0; i<=1000; i++)
        while(graph[start][i]) graph[start][i]--, dfs(i);

    stk.push(edge[start][0]);
}

int main(void)
{
    int n,m,idxCnt=0; scanf("%d%d", &n,&m);
    for(int i=0; i<n-m+1; i++)
    {
        vector<int> v;
        for(int j=0; j<m; j++)
        {
            int tmp; scanf("%d", &tmp);
            v.push_back(tmp);
        }
        vector<int> now(v.begin(), v.end()-1),
                    next(v.begin()+1, v.end());
        
        if(idx.find(now) == idx.end()) idx[now]=idxCnt++, edge[idxCnt-1]=now;
        if(idx.find(next) == idx.end()) idx[next]=idxCnt++, edge[idxCnt-1]=next;
        int from=idx[now], to=idx[next];
        indegree[to]++, outdegree[from]++, graph[from][to]++;
    }

    // 회로, 경로 판별
    int start=-1; 
    for(int i=0; i<=1000; i++) 
        if(indegree[i] < outdegree[i]) start=i;
    
    if(start != -1) dfs(start);
    else dfs(0);

    while(!stk.empty())
        printf("%d ", stk.top()), stk.pop();
}

/*
    
*/