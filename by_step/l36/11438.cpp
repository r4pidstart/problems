// https://www.acmicpc.net/problem/11438
// 2021-06-07 17:01:36 192ms
#include<bits/stdc++.h>
using namespace std;

#define MAX 17 // log2(100000)+1 == 17
vector<vector<int> > tree, parent;
vector<int> depth;

void dfs(int now, int prev=0, int level=1)
{
    depth[now]=level;
    if(tree[now].size()==1 && tree[now][0]==prev) // 끝에 도착하면
        return;
    
    for(int next : tree[now])
        if(next!=prev)
        {
            parent[next][0]=now;
            dfs(next, now, level+1);
        }
}

int get_lca(int a, int b)
{
    if(depth[a] > depth[b])
        swap(a,b); // a가 더 높이 있음.

    // 같은 레벨까지 이동
    bitset<MAX> move = depth[b]-depth[a];
    for(int i=0; i<MAX; i++)
        if(move[i]==1)
            b=parent[b][i];

    if(a==b) // 확인 안 하면 a==b일때 더 올라가버림..
        return a;
    
    // 올리면서 부모가 같은지 확인
    for(int i=MAX; i>=0; i--)
        if(parent[a][i]!=parent[b][i])
            a=parent[a][i], b=parent[b][i];
    return parent[a][0];
}

int main(void)
{
    int n; scanf("%d", &n);
    tree.assign(n+1, vector<int>()), parent.assign(n+1, vector<int>(MAX+1, 0));
    depth.assign(n+1, 0);

    // parent[a][b]: a의 2^b번째 조상
    for(int i=0; i<n-1; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    // root:1
    dfs(1); // parent[a][0] 채우기
    for(int i=1; i<=MAX; i++)
        for(int j=1; j<=n; j++)
            parent[j][i]=parent[parent[j][i-1]][i-1];

    int q; scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        printf("%d\n", get_lca(a,b));
    }
}