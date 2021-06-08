
#include<bits/stdc++.h>
using namespace std;

#define MAX 17 // log(100000)+1
vector<vector<int> > parent;
vector<vector<pair<int,int> > > dp, tree;
// dp[i][k] = i번 노드의 2^k번째 조상까지 가는 길의 최소, 최대값
vector<int> depth;

void dfs(int now, int prev, int depth_i=1)
{
    depth[now]=depth_i;
    if(tree[now].size()==1 && tree[now][0].first==prev)
        return;

    // for(vector<pair<int,int> >::iterator it=tree[now].begin(); it!=tree[now].end(); it++)
    for(auto& next : tree[now])
        if(next.first!=prev)
        {
            parent[next.first][0]=now;
            dp[next.first][0]=make_pair(next.second, next.second);
            dfs(next.first, now, depth_i+1);
        }
}

pair<int,int> get_ans(int a, int b)
{
    if(depth[a]>depth[b])
        swap(a,b);
    
    int fir=INT32_MAX, sec=INT32_MIN;
    bitset<MAX> diff=depth[b]=depth[a];
    for(int i=0; i<MAX; i++)
        if(diff[i]==1)
        {
            fir=min(fir, dp[b][i].first);
            sec=max(sec, dp[b][i].second);
            b=parent[b][i];
        }

    if(a==b)
        return {fir, sec};
    
    for(int i=MAX; i>=0; i--)
    {
        if(parent[a][i]!=parent[b][i])
        {
            fir=min({fir, dp[a][i].first, dp[b][i].first});
            sec=max({sec, dp[a][i].second, dp[b][i].second});
            a=parent[a][i], b=parent[b][i];
        }
    }

    // 부모가 다른 상태이므로 같아지도록 한번 더 이동.
    fir=min({fir, dp[a][0].first, dp[b][0].first});
    sec=max({sec, dp[a][0].second, dp[b][0].second});

    return {fir, sec};
}

int main(void)
{
    int n; scanf("%d", &n);
    depth.assign(n+1, 0), parent.assign(n+1, vector<int>(MAX+1,0));
    dp.assign(n+1, vector<pair<int,int> >(MAX+1, {100000, 0})), tree.assign(n+1, vector<pair<int,int> >());
    for(int i=0; i<n-1; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }

    dfs(1, 0);
    for(int k=1; k<MAX; k++)
        for(int i=1; i<n+1; i++)
        {
            parent[i][k]=parent[parent[i][k-1]][k-1];
            dp[i][k]={min(dp[i][k-1].first, dp[parent[i][k-1]][k-1].first), max(dp[i][k-1].second, dp[parent[i][k-1]][k-1].second)};
        }

    int q; scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        pair<int,int> ans=get_ans(a,b);
        printf("%d %d\n", ans.first, ans.second);
    }
}