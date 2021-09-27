// https://www.acmicpc.net/problem/2024
// 2021-09-28 03:03:52 0ms
#include<bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int a)
{
    if(parent[a]<0) return a;
    return parent[a]=find(parent[a]);
}

int merge(int a, int b)
{
    a=find(a), b=find(b);
    if(a==b) return 1;

    if(a<b) swap(a,b);

    parent[a]+=parent[b];
    parent[b]=a;
    return 0;
}

int main(void)
{
    int n,m,t; scanf("%d%d%d", &n,&m,&t);
    parent.assign(n+1, -1);
    vector<int> truth(t); // 0번 사람은 진실을 알고 있다고 가정한다
    for(int i=0; i<t; i++)
        scanf("%d", &truth[i]);

    for(int i : truth) // 진실을 알고 있는 사람을 묶는다
        merge(0,i);

    vector<vector<int> > people(m);
    for(int i=0; i<m; i++)
    {
        int c; scanf("%d", &c);
        for(int j=0; j<c; j++)
        {
            int tmp; scanf("%d", &tmp);
            people[i].push_back(tmp);
        }
        
        // 같은 그룹끼리 묶는다
        for(int j=0; j<people[i].size()-1; j++)
            merge(people[i][j], people[i][j+1]);
    }

    // 거짓말 할 수 있는 그룹을 확인한다
    int ans=0;
    for(int i=0; i<m; i++)
        if(find(0) != find(people[i][0])) ans++;
    printf("%d", ans);
}

/*
    
*/