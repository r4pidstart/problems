// https://www.acmicpc.net/problem/7812
// 2024-04-07 12:13:35
#include"bits/stdc++.h"
using namespace std;

int get_subtree(int now, int prev, const vector<vector<pair<int, int> > >& graph, vector<int>& subtree)
{
    if(now and graph[now].size()==1)
        return subtree[now]=1;
    
    int ret=1;
    for(auto [next, cost] : graph[now])
        if(next != prev)
            ret+=get_subtree(next, now, graph, subtree);
    return subtree[now]=ret;
}

long get_subtree_weight(int now, int prev, const vector<vector<pair<int, int> > >& graph, vector<int>& subtree, vector<long>& subtree_weight)
{
    if(now and graph[now].size()==1)
        return subtree_weight[now]=0;
    
    long ret=0;
    for(auto [next, cost] : graph[now])
        if(next != prev)
            ret+=get_subtree_weight(next, now, graph, subtree, subtree_weight) + subtree[next]*cost;
    return subtree_weight[now]=ret;
}


long solution(int now, int prev, long weight, vector<long>& ans, const vector<vector<pair<int, int> > >& graph, const vector<int>& subtree, const vector<long>& subtree_weight)
{   
    if(now and graph[now].size()==1)
        return ans[now]=weight;

    for(auto [next, cost] : graph[now])
    {
        if(next != prev)
        {
            int upper_node=graph.size()-subtree[next];
            solution(next, now, weight - subtree[next]*cost + upper_node*cost, ans, graph, subtree, subtree_weight);
        }
    }
    return ans[now]=weight;
}

int main(void)
{
    int n; scanf("%d", &n); 
    while(n)
    {
        vector<vector<pair<int, int> > > graph(n);
        for(int i=0; i<n-1; i++)
        {
            int a,b,c; scanf("%d%d%d", &a, &b, &c);
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }

        vector<int> subtree(n);
        get_subtree(0, -1, graph, subtree);
        vector<long> subtree_weight(n);
        get_subtree_weight(0, -1, graph, subtree, subtree_weight);

        vector<long> ans(n);
        solution(0, -1, subtree_weight[0], ans, graph, subtree, subtree_weight);
        printf("%ld\n", *min_element(ans.begin(), ans.end()));

        scanf("%d", &n);
    }
}

/*
    
*/