#include<bits/stdc++.h>
using namespace std;

vector<int> visited(500);
vector<vector<int> > dest;
int n,m, tree_count, flag;

void dfs(int now, int prev)
{
    visited[now]++;
    if(visited[now]!=1 || flag!=0)
    {
        flag++;
        return;
    }

    if((dest[now].size()==1 && dest[now][0]==prev)|| dest[now].size()==0)
    {
        tree_count++;
        return;
    }

    for(int next : dest[now])
        if(next!=prev)
            dfs(next, now);
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
        {
            flag=0;
            dfs(i,0);
        }

        if(tree_count==0)
            printf("Case %d: No trees.\n", case_count);
        else if(tree_count==1)
            printf("Case %d: There is one tree.\n", case_count);
        else    
            printf("Case %d: A forest of %d trees.\n", case_count, tree_count);
    }
}
