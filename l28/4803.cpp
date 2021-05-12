// https://www.acmicpc.net/problem/4803
// 2021-05-08 16:29:33 44ms
#include<bits/stdc++.h>
using namespace std;

vector<int> visited(500);
vector<vector<int> > dest;
int n,m, tree_count;

int dfs(int now, int prev)
{
    visited[now]++;
    for(int next : dest[now])
        if(next!=prev)
        {
            if(visited[next]!=0)
                return 1;
            if(dfs(next, now)!=0)
                return 1;
        }
    return 0;
}

int main(void)
{
    int case_count=0;
    while(true)
    {
        case_count++;
        tree_count=0;
        scanf("%d%d", &n,&m);
        if(n==0 && m==0)
            return 0;
        dest.clear(), dest.resize(n+1);
        visited.assign(n+1, 0);
        
        for(int i=0; i<m; i++)
        {
            int a,b; scanf("%d%d", &a, &b);
            dest[a].push_back(b);
            dest[b].push_back(a);
        }

        for(int i=1; i<=n; i++)
            if(dfs(i,0)==0)
                tree_count++;

        if(tree_count==0)
            printf("Case %d: No trees.\n", case_count);
        else if(tree_count==1)
            printf("Case %d: There is one tree.\n", case_count);
        else    
            printf("Case %d: A forest of %d trees.\n", case_count, tree_count);
    }
}
