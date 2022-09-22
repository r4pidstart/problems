// https://www.acmicpc.net/problem/14267
// 44ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n, m; scanf("%d%d", &n, &m);
    vector<int> parent(n+1), praised(n+1);
    for(int i=1; i<=n; i++)
        scanf("%d", &parent[i]);
    
    while(m--)
    {
        int a,b; scanf("%d%d", &a, &b);
        praised[a]+=b;
    }

    parent[1]=1;
    for(int i=1; i<=n; i++)
    {
        praised[i]+=praised[parent[i]];
        printf("%d ", praised[i]);
    }
}