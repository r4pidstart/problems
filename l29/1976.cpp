// https://www.acmicpc.net/problem/1976
// 2021-05-09 21:58:54 4ms
#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
// 양수이면 부모의 위치, 음수이면 해당 트리의 깊이

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

void merge(int a, int b)
{
    a=find(a), b=find(b);
    if(a==b)
        return;
    if(parent[a]<parent[b]) // a가 b보다 깊다면
    {
        parent[a]+=parent[b];
        parent[b]=a;
    }
    else
    {
        parent[b]+=parent[a];
        parent[a]=b;
    }
}

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    parent.assign(n+1,-1);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            int tmp; scanf("%d", &tmp);
            if(tmp==1)
                merge(i, j);
        }
    vector<int> root(m,0);
    for(int i=0; i<m; i++)
    {
        int tmp; scanf("%d", &tmp);
        root[i]=find(tmp);
        if(i!=0 && root[i]!=root[i-1])
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}