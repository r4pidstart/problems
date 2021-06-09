
#include<bits/stdc++.h>
using namespace std;

#define MAX 17 // log2(100000)+1
vector<vector<pair<int,int> > > tree;
vector<vector<int> > parent;
vector<vector<long long> > cost;
vector<long long> cost;
vector<int> depth;
// parent[i][k] : i 정점의 2^k번째 노드

void dfs(int now, int prev, int d=1)
{
    depth[now]=d;
    if(tree[now].size()==1 && tree[now][0].first==prev)
        return;
    
    for(auto& next : tree[now])
    {
        if(next.first!=prev)
        {
            parent[next.first][0]=now;
            cost[next.first][0]=next.second;
            dfs(next.first, now, d+1);
        }
    }
}

int get_lca(int a, int b)
{
    if(depth[a]>depth[b])
        swap(a,b);
    
    bitset<MAX> diff=depth[b]-depth[a];
    for(int i=0; i<MAX; i++)
        if(diff[i]==1)
            b=parent[b][i];

    if(a==b)
        return a;

    for(int i=MAX; i>=0; i--)
        if(parent[a][i] != parent[b][i])
            a=parent[a][i], b=parent[b][i];

    return parent[a][0];
}

long long get_ans1(int a, int b)
{
    if(depth[a]>depth[b])
        swap(a,b);
    
    long long sum=0;
    bitset<MAX> diff=depth[b]-depth[a];
    for(int i=0; i<MAX; i++)
        if(diff[i]==1)
        {
            sum+=cost[b][i];
            b=parent[b][i];
        }

    if(a==b)
        return sum;

    for(int i=MAX; i>=0; i--)
        if(parent[a][i] != parent[b][i])
        {
            sum+=cost[a][i]+cost[b][i];
            a=parent[a][i], b=parent[b][i];
        }

    sum+=cost[a][0]+cost[b][0];

    return sum;
}

int get_ans2(int a, int b, int c)
{
    int lca=get_lca(a,b);
    int dep_a=depth[a]-depth[lca], dep_b=depth[b]-depth[lca];
    // c th node in route (a to b)
    if(dep_a >= c-1)
    {
        bitset<MAX> diff2=c-1;
        for(int i=0; i<MAX; i++)
            if(diff2[i]==1)
                a=parent[a][i];
        return a;
    }
    else
    {
        bitset<MAX> diff2=dep_b-(c-dep_a)+1;
            for(int i=0; i<MAX; i++)
                if(diff2[i]==1)
                    b=parent[b][i];
            return b;
    }
}

int main(void)
{
    int n; scanf("%d", &n);
    tree.assign(n+1, vector<pair<int,int> >());
    parent.assign(n+1, vector<int>(MAX+1, 0));
    cost.assign(n+1, vector<long long>(MAX+1, 0));
    depth.assign(n+1, -1);
    for(int i=0; i<n-1; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }

    dfs(1,0);

    for(int k=1; k<MAX+1; k++)
        for(int i=1; i<n+1; i++)
        {
            parent[i][k]=parent[parent[i][k-1]][k-1];
            cost[i][k]=cost[parent[i][k-1]][k-1]+cost[i][k-1];
        }
    
    int q; scanf("%d", &q);
    while(q--)
    {
        int num; scanf("%d", &num);
        if(num==1)
        {
            int a,b; scanf("%d%d", &a,&b);
            printf("%lld\n", get_ans1(a,b));
        }
        else
        {
            int a,b,c; scanf("%d%d%d", &a,&b,&c);
            printf("%d\n", get_ans2(a,b,c));
        }
    }
}