// https://www.acmicpc.net/problem/16562
// 2021-06-18 13:32:14 4ms
#include<bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int a)
{
    if(parent[a]<0)
        return a;
    return parent[a]=find(parent[a]);
}

int merge(int a, int b)
{
    a=find(a), b=find(b);
    if(a==b)
        return 1;
    
    if(a!=0 && parent[a]>parent[b])
        swap(a,b);
    
    parent[a]+=parent[b];
    parent[b]=a;
    return 0;
}

int main(void)
{
    int n,m,k; scanf("%d%d%d", &n,&m,&k);
    parent.assign(n+1, -1);

    vector<pair<int,int> > cost(n+1); // cost, index
    cost[0]={0,0};
    for(int i=1; i<=n; i++)
    {
        cost[i].second=i;
        scanf("%d", &cost[i].first);
    }

    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        merge(a,b);
    }

    // 준석이는 0번. parent[0]==n+1이 되면 친구를 다 사귈 수 있다.
    sort(cost.begin(), cost.end());
    int init_k=k;
    for(int i=1; i<=n; i++)
    {
        if(parent[0]==-(n+1))
            break;
        if(find(cost[i].second) == 0) // 이미 친구라면
            continue;
        if(cost[i].first <= k)
        {
            merge(0, cost[i].second);
            k-=cost[i].first;
        }
        else
        {
            printf("Oh no");
            return 0;
        }
    }
    printf("%d", init_k-k);


}