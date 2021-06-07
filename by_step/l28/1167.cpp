// https://www.acmicpc.net/problem/1167
// 2021-05-03 01:08:52 112ms
#include<bits/stdc++.h>
using namespace std;

pair<int,int> dfs(int now, int prev, int d, vector<vector<pair<int,int> > > &tree)
{
    if(tree[now].size()==1 && tree[now][0].first==prev)
        return make_pair(d, now);
    
    pair<int,int> ret={0,0};
    for(pair<int,int> next : tree[now])
        if(next.first!=prev)
            ret=max(ret, dfs(next.first, now, d+next.second, tree));
    return ret;
}

int main(void)
{
    int v; scanf("%d", &v);
    vector<vector<pair<int, int> > > tree(v+1);
    // next, distance
    for(int i=0; i<v; i++)
    {
        int a, b, d; scanf("%d", &a);
        vector<int> tmp;
        while(scanf("%d", &b))
        {
            if(b==-1) break;
            scanf("%d", &d);
            tree[a].push_back({b,d});
        }
    }
    printf("%d", dfs(dfs(1, 0, 0, tree).second, 0, 0, tree).first);
}