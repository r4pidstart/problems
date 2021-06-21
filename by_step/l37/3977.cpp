// https://www.acmicpc.net/problem/3977
// 2021-06-21 22:45:37 268ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > area, sccarr;
vector<int> finished, visited, sccidx, indegree;
stack<int> stk;
int scccnt=0;

int targanDFS(int now)
{
    static int visitcnt=0;
    if(visited[now])
        return visited[now];

    stk.push(now);
    int low_link=visited[now]=visitcnt++;

    for(int next : area[now])
    {
        if(!finished[next])
            low_link=min(low_link, targanDFS(next));
    }

    if(visited[now]==low_link)
    {
        vector<int> scc;
        while(true)
        {
            int v=stk.top();
            stk.pop();

            finished[v]++;
            sccidx[v]=scccnt;
            scc.push_back(v);
            if(now==v)
                break;
        } 
        scccnt++;
        sccarr.push_back(scc);
    }
    return low_link;
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m; scanf("%d%d", &n,&m);

        area.assign(n,vector<int>());
        finished.assign(n,0), visited.assign(n,0);
        sccidx.assign(n,-1), indegree.assign(n,0);
        sccarr.clear();
        scccnt=0;

        for(int i=0; i<m; i++)
        {
            int a,b; scanf("%d%d", &a,&b);
            area[a].push_back(b);
        }
        for(int i=0; i<n; i++)
            targanDFS(i);

        for(int i=0; i<n; i++)
            for(int next : area[i])
                if(sccidx[i]!=sccidx[next])
                    indegree[sccidx[next]]++;

        // 정답이 포함된 scc찾기
        deque<int> sccdq;
        for(int i=0; i<scccnt; i++)
        {
            if(indegree[i]==0)
                sccdq.push_back(i);
        } 
        
        // 정답이 포함된 scc가 2개 이상이라면 불가능한 경우.
        if(sccdq.size()!=1)
            printf("Confused\n");
        else
        {
            deque<int> dq;
            for(int target : sccdq)
                dq.insert(dq.end(), sccarr[target].begin(), sccarr[target].end());

            sort(dq.begin(), dq.end());

            for(int i : dq)
                printf("%d\n", i);
        }
        printf("\n");
    }
}