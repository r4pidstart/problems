// https://www.acmicpc.net/submit/3176
// 2021-06-08 11:51:27 392ms
#include<bits/stdc++.h>
using namespace std;

#define MAX 17 // log(100000)+1
vector<vector<int> > parent, dp_min, dp_max;
vector<vector<pair<int,int> > > tree;
vector<int> depth;

void dfs(int now, int prev=0, int d=1)
{
    depth[now]=d;
    if(tree[now].size()==1 && tree[now][0].first==prev)
        return;

    for(auto& next : tree[now])
        if(next.first!=prev)
        {
            dp_min[next.first][0]=next.second, dp_max[next.first][0]=next.second;
            parent[next.first][0]=now;
            dfs(next.first, now, d+1);
        }
}

pair<int,int> get_ans(int a, int b)
{
    if(depth[a]>depth[b])
        swap(a,b);

    int ma=INT32_MIN, mi=INT32_MAX;
    bitset<MAX> diff=depth[b]-depth[a];
    for(int i=0; i<MAX; i++)
        if(diff[i]==1)
        {
            ma=max(ma, dp_max[b][i]);
            mi=min(mi, dp_min[b][i]);
            b=parent[b][i];
        }

    if(a==b) // 같은 경우
        return {ma, mi};

    for(int i=MAX; i>=0; i--)
        if(parent[a][i]!=parent[b][i])
        {
            ma=max({ma, dp_max[a][i], dp_max[b][i]});
            mi=min({mi, dp_min[a][i], dp_min[b][i]});
            a=parent[a][i], b=parent[b][i];
        }

    ma=max({ma, dp_max[a][0], dp_max[b][0]});
    mi=min({mi, dp_min[a][0], dp_min[b][0]});

    return {ma, mi};
}

int main(void)
{
    int n; scanf("%d", &n);
    parent.assign(n+1, vector<int>(MAX+1));
    dp_min.assign(n+1, vector<int>(MAX+1)), dp_max.assign(n+1, vector<int>(MAX+1));
    tree.assign(n+1, vector<pair<int,int> >());
    depth.assign(n+1, 0);
    for(int i=0; i<n-1; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }

    dfs(1);
    for(int k=1; k<MAX+1; k++)
        for(int i=1; i<n+1; i++)
        {
            parent[i][k]=parent[parent[i][k-1]][k-1];
            dp_min[i][k]=min(dp_min[parent[i][k-1]][k-1], dp_min[i][k-1]);
            dp_max[i][k]=max(dp_max[parent[i][k-1]][k-1], dp_max[i][k-1]);
        }

    int q; scanf("%d", &q);
    while(q--)
    {
        int a,b; scanf("%d%d", &a,&b);
        pair<int,int> ans=get_ans(a,b);
        printf("%d %d\n", ans.second, ans.first);
    }
}