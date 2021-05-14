// https://www.acmicpc.net/problem/2887
// 2021-05-15 07:38:02 128ms
#include<bits/stdc++.h>
using namespace std;

typedef struct _point
{
    int x,y,z;
}_point;

vector<int> parent;
vector<pair<int, int> > x,y,z;

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

int main(void)
{
    int n; scanf("%d", &n);
    x.resize(n), y.resize(n), z.resize(n), parent.assign(n,-1);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d%d", &x[i].first, &y[i].first, &z[i].first);
        x[i].second=y[i].second=z[i].second=i;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());
    vector<pair<int, pair<int, int> > > edge; // cost, a,b
    for(int i=1; i<n; i++)
    {
        edge.push_back({abs(x[i].first-x[i-1].first), {x[i].second, x[i-1].second}});
        edge.push_back({abs(y[i].first-y[i-1].first), {y[i].second, y[i-1].second}});
        edge.push_back({abs(z[i].first-z[i-1].first), {z[i].second, z[i-1].second}});
    }
    sort(edge.begin(), edge.end()); // 비용순 정렬
    
    long long sum=0, count=0;
    for(auto &target : edge)
    {
        if(merge(target.second.first, target.second.second)!=1)
            sum+=target.first, count++;
        if(n-count==1)
            break;
    }

    printf("%lld", sum);
}