// https://www.acmicpc.net/problem/2666
// 2021-09-14 03:41:26 4ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<int> > > memo; 
vector<int> arr; 
int a,b,c,d;

void dfs(int q, int l, int r, int cnt=0)
{
    if(q==d)
    {
        memo[q][l][r]=min(memo[q][l][r], cnt);
        return;
    }
    if(l>r) swap(l,r);
    if(memo[q][l][r] <= cnt) return;
    memo[q][l][r]=cnt;
    if(arr[q]==l || arr[q]==r) dfs(q+1,l,r,cnt);
    // l <-
    if(l-1>=0 && l-1!=r)
    {
        if(arr[q]==l-1) dfs(q+1,l-1,r,cnt+1);
        else dfs(q,l-1,r,cnt+1);
    }
    // l ->
    if(l+1<a && l+1!=r)
    {
        if(arr[q]==l+1) dfs(q+1,l+1,r,cnt+1);
        else dfs(q,l+1,r,cnt+1);
    }
    // r <-
    if(r-1>=0 && r-1!=l)
    {
        if(arr[q]==r-1) dfs(q+1,l,r-1,cnt+1);
        else dfs(q,l,r-1,cnt+1);
    }
    // r ->
    if(r+1<a && r+1!=l)
    {
        if(arr[q]==r+1) dfs(q+1,l,r+1,cnt+1);
        else dfs(q,l,r+1,cnt+1);
    }
}

int main(void)
{
    scanf("%d%d%d%d", &a,&b,&c,&d);
    memo.assign(d+1, vector<vector<int> >(a, vector<int>(a,INT32_MAX/2)));
    // memo[i][j][k] : i번째 벽장까지 사용할 수 있고, 그 때 j,k 벽장이 비어있는 최소 경우의 수
    arr.assign(d,0);
    for(int i=0; i<d; i++)
    {
        scanf("%d", &arr[i]);
        arr[i]--;
    }

    dfs(0,b-1,c-1);
    int ans=INT32_MAX;
    for(int i=0; i<a; i++)
        for(int j=0; j<a; j++)
            ans=min(ans, memo[d][i][j]);
    printf("%d", ans);
}

/*

*/