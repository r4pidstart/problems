// https://www.acmicpc.net/problem/12767
// 2024-02-19 23:50:52
#include"bits/stdc++.h"
using namespace std;

int insert(int now, int target, map<int, pair<int,int> >& graph)
{
    if(now < target)
    {
        if(graph[now].first)
            insert(graph[now].first, target, graph);
        else
            graph[now].first=target;
    }
    else if(now > target)
    {
        if(graph[now].second)
            insert(graph[now].second, target, graph);
        else
            graph[now].second=target;
    }
    return 0;
}

int is_same_graph(int n1, int n2, map<int, pair<int,int> >& g1, map<int, pair<int,int> >& g2)
{
    int ret=0;

    if(g1[n1].first or g2[n2].first)
    {
        if(g1[n1].first and g2[n2].first)
            ret+=is_same_graph(g1[n1].first, g2[n2].first, g1, g2);
        else
            return 1;
    }

    if(g1[n1].second or g2[n2].second)
    {
        if(g1[n1].second and g2[n2].second)
            ret+=is_same_graph(g1[n1].second, g2[n2].second, g1, g2);
        else
            return 1;
    }

    return ret;
}

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    vector<vector<int> > arr(n, vector<int>(k));
    for(int i=0; i<n; i++)
        for(int j=0; j<k; j++)
            scanf("%d", &arr[i][j]);
    
    vector<int> root(n);
    vector<map<int, pair<int,int> > > graph(n+1);
    for(int i=0; i<n; i++)
    {
        root[i]=arr[i][0];
        for(int v : arr[i])
            insert(root[i], v, graph[i]);
    }

    vector<int> is_vaild(n, 1);
    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
        {
            if(is_vaild[j] and !is_same_graph(root[i], root[j], graph[i], graph[j]))
                is_vaild[j]=0;
        }
    printf("%d", accumulate(is_vaild.begin(), is_vaild.end(), 0));
}

/*
    
*/