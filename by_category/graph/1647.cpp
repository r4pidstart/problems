// https://www.acmicpc.net/problem/1647
// 2021-06-12 22:10:46 552ms
#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
priority_queue<pair<int, pair<int,int> > , vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;

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
    if(parent[a] > parent[b])
        swap(a,b);
    
    parent[a]+=parent[b];
    parent[b]=a;

    return 0;
} 
int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    parent.assign(n+1, -1);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        pq.push({c,{a,b}});
    }    
    int ans=0, count=0;
    while(count!=n-2)
    {
        int weigh=pq.top().first, a=pq.top().second.first, b=pq.top().second.second;
        pq.pop();
        if(!merge(a,b))
            ans+=weigh, count++;
    }  
    printf("%d", ans);
}