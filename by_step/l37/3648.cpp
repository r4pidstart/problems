// https://www.acmicpc.net/problem/3648
// 2021-07-06 00:29:09 20ms
#include<bits/stdc++.h>
using namespace std;

int scccnt=1;
vector<vector<int> > graph; 
vector<int> sccidx, finished, visited;
stack<int> stk;

int targanDFS(int now)
{
    static int visit_cnt=1;
    if(visited[now]) return visited[now];

    int low_link=visited[now]=visit_cnt++;
    stk.push(now);

    for(int next : graph[now])
        if(!finished[next])
            low_link=min(low_link, targanDFS(next));
        
    if(low_link == visited[now])
    {
        while(true)
        {
            int v=stk.top();
            stk.pop();
            sccidx[v]=scccnt;
            finished[v]++;
            if(v==now)
                break;
        }
        scccnt++;
    }

    return low_link;
}

int main(void)
{
    int n,m;
    while(scanf("%d%d", &n,&m)!=EOF)
    {
        graph.assign(2*n+1, vector<int>());
        sccidx=finished=visited=vector<int>(2*n+1, 0);
        for(int i=0; i<m; i++)
        {
            int a,b; scanf("%d%d", &a,&b);
            graph[-a+n].push_back(b+n);
            graph[-b+n].push_back(a+n);
        }
        graph[-1+n].push_back(1+n);
        // 1번이 무조건 합격해야 함.
         
        for(int i=0; i<2*n+1; i++)
            if(!finished[i])
                targanDFS(i);

        int flag=0;
        for(int i=0; i<n; i++)
            if(sccidx[i]==sccidx[2*n-i])
                flag++;

        if(flag)
            printf("no\n");
        else
            printf("yes\n");
    }
}

/*
    2-sat, ~A -> B, ~B -> A, A,~A가 같은 scc에 있으면 불가능.
*/