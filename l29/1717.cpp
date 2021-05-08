// https://www.acmicpc.net/problem/1717
// 2021-05-09 01:15:22 56ms
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
    if(parent[a]<parent[b])
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
    int n,m;
    scanf("%d%d", &n, &m);
    parent.assign(n+1, -1);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        if(a==0) // 집합 합치기
            merge(b,c);
        else // 같은 집합인지 확인하기
        {
            if(find(c)==find(b))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

}