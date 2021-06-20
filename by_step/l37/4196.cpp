// https://www.acmicpc.net/problem/4196
// 2021-06-20 14:08:48 192ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > dest(100001), sccarr;
vector<int> finished, discovered, sccid, indegree;
stack<int> stk;

int targan_dfs(int now)
{
    if(discovered[now]) return discovered[now];

    static int visit_cnt=1;
    int low_link=discovered[now]=visit_cnt++;
    stk.push(now);

    for(int next : dest[now])
    {
        // 탐색하면서 사이클 확인
        if(finished[next]==0)
            low_link=min(low_link, targan_dfs(next));
    }

    if(low_link==discovered[now]) // 사이클이 있으면
    {
        vector<int> scc;
        int sid=sccarr.size();
        while(true)
        {
            int v=stk.top();
            finished[v]++;
            scc.push_back(v);
            sccid[v]=sid;
            stk.pop();
            if(v==now) break;
        }
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
        // dest.assign(n+1, vector<int>()); -> invalid pointer
        finished.assign(n+1, 0), discovered.assign(n+1, 0);
        sccid.assign(n+1, 0), indegree.assign(n+1, 0);
        sccarr.clear();
        for(int i=1; i<=n; i++)
            dest[i].clear();

        for(int i=0; i<m; i++)
        {
            int a,b; scanf("%d%d", &a,&b);
            dest[a].push_back(b);
        }

        for(int i=1; i<=n; i++)
            targan_dfs(i);

        for(int i=1; i<=n; i++)
            for(int next : dest[i])
            {
                if(sccid[i]!=sccid[next])
                    indegree[sccid[next]]++;
            }

        int ans=0;
        for(int i=sccarr.size()-1; i>=0; i--) 
            if(indegree[i]==0) ans++;

        printf("%d\n", ans);
    }
} 