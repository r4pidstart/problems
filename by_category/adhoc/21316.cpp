// https://www.acmicpc.net/problem/21316
// 2024-02-06 02:08:54
#include"bits/stdc++.h"
using namespace std;

int find_spica(const vector<vector<int> >& graph)
{
    vector<int> ans{1, 2, 3};
    for(int i=1; i<13; i++)
    {
        vector<int> tmp;
        for(int next : graph[i])
            tmp.push_back(graph[next].size());
        sort(tmp.begin(), tmp.end());
        if(tmp==ans)
            return i;
    }
    assert(false);
    return 0;
}

int main(void)
{
    vector<vector<int> > graph(13);
    for(int i=0; i<12; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    printf("%d", find_spica(graph));
}

/*
    
*/