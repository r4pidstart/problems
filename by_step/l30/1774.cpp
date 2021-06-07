// https://www.acmicpc.net/problem/1774
// 2021-05-13 23:48:06 184ms
#include<bits/stdc++.h>
using namespace std;

vector<int> parent(1001, -1);
vector<pair<int, int> > point(1);

int find(int a)
{
    if(parent[a]>=0)
    {
        int tmp=a;
        while(parent[a]>=0)
            a=parent[a];
        parent[tmp]=a;
    }
    return a;
}

int merge(int a, int b)
{
    a=find(a), b=find(b);
    if(a==b)
        return 1;
    
    if(parent[a]>parent[b])
        swap(a,b);
    
    parent[a]+=parent[b];
    parent[b]=a;
    return 0;
}

long double get_dist(pair<int,int> a, pair<int,int> b)
{
    return sqrt((long long)(a.first-b.first)*(a.first-b.first) + (long long)(a.second-b.second)*(a.second-b.second));
}

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    for(int i=0; i<n; i++)
    {
        int x,y; scanf("%d%d", &x,&y);
        point.push_back({x,y});
    }
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        merge(a,b);
    }
    long double sum=0;
    int e=m;
    priority_queue<pair<long double, pair<int, int> > > pq;
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            pq.push({-get_dist(point[i], point[j]), {i,j}});
    while(!pq.empty() && n-e!=1)
    {
        pair<int,int> now = pq.top().second;
        if(merge(now.first,now.second)==0)
            e++, sum-=pq.top().first; // 음수
        pq.pop();   
    }
    printf("%.2Lf", sum);
}