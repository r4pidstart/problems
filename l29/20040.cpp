// https://www.acmicpc.net/problem/20040
// 2021-05-10 18:34:38 160ms
#include<bits/stdc++.h>
using namespace std;

vector<int> parent;

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
    
    if(parent[a]>parent[b]) // a보다 b가 깊다면
        swap(a,b);
    
    parent[a]+=parent[b];
    parent[b]=a;
    return 0;
}

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    parent.assign(n+1, -1);
    for(int i=1; i<=m; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        if(merge(a,b)==1) // 사이클이 형성되면
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("0");
}