// https://www.acmicpc.net/problem/28102
// 2024-06-18 00:15:34
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n,m,q; cin >> n >> m >> q;
    vector<vector<int> > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> used(n+1);
    vector<vector<int> > component;
    for(int i=1; i<=n; i++)
    {   
        // get components
        if(!used[i])
        {
            queue<int> q;
            q.push(i);
            used[i]=1;
            component.push_back({i});

            while(q.size())
            {
                int now=q.front();
                q.pop();

                for(int next : graph[now])
                    if(!used[next])
                    q.push(next), used[next]=1, component.back().push_back(next);
            }
        }
    }
    
    vector<int> where_is(n+1);
    int comp_idx=0;
    vector<vector<int> > visited(n+1, vector<int>(2));
    for(auto& arr : component)
    {
        for(int i : arr)
            where_is[i]=comp_idx;

        queue<pair<int, int> > q;
        q.push({arr[0], 0});
        visited[arr[0]][0]=1;

        while(q.size())
        {
            auto [now, yes]=q.front();
            q.pop();

            for(int next : graph[now])
                if(!visited[next][!yes])
                    visited[next][!yes]=1, q.push({next, !yes});
        }

        comp_idx++;
    }

    while(q--)
    {
        int a,b,c; cin >> a >> b >> c;
        if(where_is[a] != where_is[b])
        {
            cout << "No\n";
            continue;
        }
        // c가 짝수일때 홀수번 이동해서만 도달할 수 있다면 no?
        if(c%2==0 and (!(visited[a][0] and visited[b][0]) and !(visited[a][1] and visited[b][1])))
        {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
    }
}

/*
    
*/