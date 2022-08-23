// https://www.acmicpc.net/problem/17250
// 2022-08-24 01:35:14 68ms
#include"bits/stdc++.h"
using namespace std;

vector<long long> parent;

int find(int n)
{
    if(parent[n]<0) return n;
    return parent[n]=find(parent[n]);
}

long long merge(int a, int b)
{
    a=find(a), b=find(b);
    if(a==b) return parent[a];
    if(parent[a]<parent[b]) swap(a,b);

    parent[b]+=parent[a];
    parent[a]=b;
    return parent[b];
}
int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    parent.assign(n+1, 0);
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        parent[i+1]=-a;
    }
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        printf("%lld\n", -merge(a,b));
    }        
}

/*
    
*/