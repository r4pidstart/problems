// https://www.acmicpc.net/problem/6416
// 2021-10-01 03:37:33 0ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
vector<int> root_check, visited;

int dfs(int now)
{
    if(visited[now]) return 1;
    visited[now]=1;

    int ret=0;
    for(int next : graph[now])
        ret+=dfs(next);
    return ret;
}

void solve(int tc)
{
    // 부모 노드가 없는 노드를 루트로 간주.
    // 순회로 트리인지 확인
    int cnt=0, nodeCnt=0;
    graph.assign(10001, vector<int>());
    root_check.assign(10001, -1), visited.assign(10001, 0);
    while(true)
    {
        int a,b; scanf("%d%d", &a, &b);
        if(a==b && a==0) break;
        if(a==b && a==-1) exit(0);
        if(root_check[a]==-1) nodeCnt++;
        if(root_check[b]==-1) nodeCnt++;
        // a to b
        if(root_check[a]==-1) root_check[a]=1;
        root_check[b]=0;

        graph[a].push_back(b);
        cnt++;
    }
    printf("Case %d ", tc);

    int root=0;
    for(int i=0; i<1000; i++)
        if(root_check[i]==1)
        {
            // 루트가 여러개면 트리가 아님.
            if(root!=0)
            {
                printf("is not a tree.\n");
                return;
            }
            else root=i;
        }

    if(root==0)
    {
        if(cnt==0) // 공집합
            printf("is a tree.\n");
        else
            printf("is not a tree.\n");
    }
    else if(!dfs(root) && nodeCnt==accumulate(visited.begin(), visited.end(), 0))
        printf("is a tree.\n");
    else
        printf("is not a tree.\n");
}

int main(void)
{
    int cnt=1;
    while(true)
        solve(cnt++);
}

/*
    
*/