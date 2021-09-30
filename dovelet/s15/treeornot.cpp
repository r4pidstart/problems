// http://220.89.64.243/30stair/treeornot/treeornot.php?pname=treeornot
//
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > graph(1000, vector<int>());
vector<int> root_check(1000, -1), visited(1000, 0);

int dfs(int now)
{
    if(visited[now]) return 1;
    visited[now]=1;

    int ret=0;
    for(int next : graph[now])
        ret+=dfs(next);
    return ret;
}

int main(void)
{
    // 부모 노드가 없는 노드를 루트로 간주.
    // 순회로 트리인지 확인
    int cnt=0;
    while(true)
    {
        int a,b; scanf("%d%d", &a, &b);
        if(a==b && a==0) break;
        // a to b
        if(root_check[a]==-1) root_check[a]=1;
        root_check[b]=0;

        graph[a].push_back(b);
        cnt++;
    }

    int root=0;
    for(int i=0; i<1000; i++)
        if(root_check[i]==1)
        {
            // 루트가 여러개면 트리가 아님.
            if(root!=0)
            {
                printf("not a tree");
                return 0;
            }
            else root=i;
        }

    if(root==0)
    {
        if(cnt==0) // 공집합
            printf("tree");
        else
            printf("not a tree");
    }
    else if(dfs(root))
        printf("not a tree");
    else
        printf("tree");
}

/*
    
*/