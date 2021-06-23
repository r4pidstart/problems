
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > dest, sccarr, dag_dest;
vector<int> visited, finished, atm, restaurant, sccidx, scccash, restaurant_scc, memo;
stack<int> stk;

int targanDFS(int now)
{
    if(visited[now]) return visited[now];
    static int visit_cnt=0;
    int low_link=visited[now]=visit_cnt++;
    stk.push(now);

    for(int next : dest[now])
        if(!finished[next])
            low_link=min(low_link, targanDFS(next));

    if(low_link==visited[now])
    {
        vector<int> scc;
        int index=sccarr.size();
        while(true)
        {
            int v=stk.top();
            stk.pop();
            finished[v]++;
            scc.push_back(v);
            sccidx[v]=index;
            scccash[index]+=atm[v];
            if(restaurant[v])
                restaurant_scc[index]=1;

            if(v==now)
                break;
        }
        sccarr.push_back(scc);
    }
    return low_link;
}

int dp(int now)
{
    int tmp=0;
    int& ret=memo[now];
    if(ret!=-1)
        return ret;
    for(int next : dag_dest[now])
        tmp=max(tmp, dp(next));
    
    if(tmp==0)
    {
        if(!restaurant_scc[now])
            return ret=0; // 직전 레스토랑이 있는 scc와 총 합이 같아짐.
        return ret=scccash[now];
    }
    else
        return ret=tmp+scccash[now];
}

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    dest.assign(n+1, vector<int>()), dag_dest.assign(n+1, vector<int>());
    visited.assign(n+1, 0), finished.assign(n+1, 0), scccash.assign(n+1, 0);
    restaurant.assign(n+1, 0), atm.assign(n+1, 0), sccidx.assign(n+1, -1);
    restaurant_scc.assign(n+1, 0), memo.assign(n+1, -1);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        dest[a].push_back(b);
    }
    for(int i=1; i<=n; i++)
        scanf("%d", &atm[i]);
    
    int restaurant_cnt, start;
    scanf("%d%d", &start, &restaurant_cnt);
    for(int i=0; i<restaurant_cnt; i++)
    {
        int a; scanf("%d", &a);
        restaurant[a]=1;
    }

    for(int i=1; i<=n; i++)
        if(!finished[i])
            targanDFS(i);

    for(int i=1; i<=n; i++)
        for(int next : dest[i])
            if(sccidx[i]!=sccidx[next])
                dag_dest[sccidx[i]].push_back(sccidx[next]);

    printf("%d", dp(sccidx[start]));
}