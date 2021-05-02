// https://www.acmicpc.net/problem/11725
// 2021-05-02 22:59:53 60ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > tree(n+1); 
    for(int i=1; i<n; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    queue<int> bfs;
    vector<int> ans(n+1,0);
    bfs.push(1);
    while(!bfs.empty())
    {
        int now=bfs.front();
        bfs.pop();
        for(auto it=tree[now].begin(); it!=tree[now].end(); it++)
        {
            if(*it!=now && *it!=ans[now])
            {
                ans[*it]=now;
                bfs.push(*it);
            }
        }
    }
        for(int i=2; i<=n; i++)
            printf("%d\n", ans[i]);
}