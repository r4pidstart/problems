// https://www.acmicpc.net/problem/2213
// 2021-05-23 03:38:36 8ms
#include<bits/stdc++.h>
using namespace std;

vector<int> weigh, selected_node;
vector<vector<int> > dest, dp;

int dfs(int prev, int now, int selected)
{
    if(dp[now][selected]!=-1) // 이미 방문했다면
        return dp[now][selected];

    dp[now][selected]=selected!=0 ? weigh[now]:0;
    for(int next : dest[now])
    {
        if(next==prev)  continue;
        if(selected==1) // 다음 선택 불가능
            dp[now][1]+=dfs(now, next, 0);
        else
            dp[now][0]+=max(dfs(now, next, 1), dfs(now, next, 0));
    }
    return dp[now][selected];
}

void check(int prev, int now, int prev_sel)
{
    int sel;
    if(prev_sel == 0 && dp[now][1] > dp[now][0])
    { // 이전 정점이 선택되지 않았고, 현재 정점을 선택하는것이 더 큰 경우
        selected_node.push_back(now);
        sel=1;
    }
    else 
        sel=0;
    
    for(int next : dest[now])
        if(next != prev)
            check(now, next, sel);
}

int main(void)
{
    int n; scanf("%d", &n);
    weigh.assign(n+1, 0), dest.assign(n+1, vector<int>());
    dp.assign(n+1, vector<int>(2, -1));
    for(int i=1; i<=n; i++)
        scanf("%d", &weigh[i]);
    for(int i=1; i<n; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        dest[a].push_back(b);
        dest[b].push_back(a);
    }
    printf("%d\n", max(dfs(-1, 1, 0), dfs(-1, 1, 1)));  
    check(-1, 1, 0);
    sort(selected_node.begin(), selected_node.end());
    for(int target : selected_node)
        printf("%d ", target);
    return 0;
}