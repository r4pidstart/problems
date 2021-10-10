// https://www.acmicpc.net/problem/2250
// 2021-10-11 04:31:08 4ms
#include<bits/stdc++.h>
using namespace std;

vector<int> indegree;
vector<pair<int,int> > graph, width;
int cnt=1;
void traverse(int now, int depth)
{
    if(width.size() == depth) width.push_back({INT32_MAX, INT32_MIN});

    if(graph[now].first != -1)
        traverse(graph[now].first, depth+1);
    
    width[depth].first=min(width[depth].first, cnt);
    width[depth].second=max(width[depth].second, cnt++);

    if(graph[now].second != -1)
        traverse(graph[now].second, depth+1);

}

int main(void)
{
    int n; scanf("%d", &n);
    graph.assign(n+1, {});
    indegree.assign(n+2, 0);
    for(int i=0; i<n; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        indegree[b+1]++, indegree[c+1]++; // because of -1
        graph[a]={b,c};
    }

    // find root
    for(int i=1; i<=n; i++) if(indegree[i+1]==0) traverse(i, 0);
    int ansL=-1, ansW=-1;
    for(int i=0; i<width.size(); i++)
        if(ansW < width[i].second-width[i].first+1)
            ansL=i+1, ansW=width[i].second-width[i].first+1;
    printf("%d %d", ansL, ansW);
}

/*
    
*/