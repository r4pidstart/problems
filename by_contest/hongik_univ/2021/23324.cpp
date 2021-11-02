// https://www.acmicpc.net/problem/23324
// 2021-11-03 04:06:31 E
#include<bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int a)
{
    if(parent[a] > 0)
        return parent[a]=find(parent[a]);
    return a;
}

int merge(int a, int b)
{
    a=find(a), b=find(b);
    if(a==b) return 1;
    
    if(-parent[a] < -parent[b]) swap(a,b);

    parent[a]+=parent[b];
    parent[b]=a;
    return 0;
}

int main(void)
{
    int n,m,k; scanf("%d%d%d", &n,&m,&k);
    // k번째 간선이 연결하는 두 점이, 같은 집합에 있다면 0, 다른 집합에 있다면, 집합 A의 정점 갯수 * 집합 B의 정점 갯수
    parent.assign(n+1, -1);

    int A,B;
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        if(i==k-1) A=a, B=b;
        else merge(a,b);
    }

    if(find(A)==find(B)) // 같은 집합
        printf("0");
    else
        printf("%lld", (long long)parent[find(A)] * parent[find(B)]);
}

/*
    
*/