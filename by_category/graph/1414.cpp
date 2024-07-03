// https://www.acmicpc.net/problem/1414
// 2024-07-02 11:50:44
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    vector<vector<pair<int, int> > > graph(n);
    int edge_sum=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            char c; cin >> c;
            if(islower(c))
                graph[i].push_back({j, c-'a'+1}),
                graph[j].push_back({i, c-'a'+1}), edge_sum+=c-'a'+1;
                
            else if(isupper(c))
                graph[i].push_back({j, c-'A'+27}), 
                graph[j].push_back({i, c-'A'+27}), edge_sum+=c-'A'+27;
        }
    
    int used_sum=0;
    vector<int> used(n);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    pq.push({0, 0});
    while(pq.size())
    {
        auto [dist, now]=pq.top();
        pq.pop();

        if(used[now]) continue;

        used_sum+=dist;
        used[now]=1;

        for(auto [next, ndist] : graph[now])
            if(!used[next])
                pq.push({ndist, next}); 
    }

    if(accumulate(used.begin(), used.end(), 0)==n)
        cout << edge_sum - used_sum;
    else
        cout << -1;
}

/*
    
*/