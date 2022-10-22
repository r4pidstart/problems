// https://www.acmicpc.net/problem/17352
// 2022-10-23 01:14:43
#include"bits/stdc++.h"
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
    
    if(parent[a] > parent[b])
        swap(a,b);
    
    parent[a]+=parent[b];
    parent[b]=a;
    return 0;
}

int main(void)
{
    int n; scanf("%d", &n);
    parent.assign(n+1, -1);
    for(int i=0; i<n-2; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        merge(a,b);
    }

    for(int i=1; i<=n; i++)
        if(parent[i]<0)
            printf("%d ", i);
}

/*
    
*/