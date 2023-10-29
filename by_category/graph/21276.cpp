// https://www.acmicpc.net/problem/21276
// 2023-10-29 12:43:57
#include"bits/stdc++.h"
using namespace std;

int main(void)
{  
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
#endif
    int n; cin >> n;
    vector<string> names(n);
    for(int i=0; i<n; i++)
        cin >> names[i];
    sort(names.begin(), names.end());

    // topological sort
    int m; cin >> m;
    map<string, int> indegree;
    for(string& s : names)
        indegree[s];

    map<string, vector<string> > graph;
    for(int i=0; i<m; i++)
    {
        string a,b; cin >> a >> b;
        graph[b].push_back(a);
        indegree[a]++;
    }

    queue<string> q;
    vector<string> tree_start;
    for(auto& [a, b] : indegree)
    {
        if(b==0)
            q.push(a), tree_start.push_back(a);
    }

    map<string, vector<string> > tree;
    while(q.size())
    {
        string now=q.front();
        q.pop();

        for(string& next : graph[now])
        {
            indegree[next]--;
            if(indegree[next]==0)
                q.push(next), tree[now].push_back(next);
        }
    }

    cout << tree_start.size() << '\n';
    for(string& s : tree_start)
        cout << s << ' ';
    cout << '\n';

    for(string& a : names)
    {
        cout << a << ' ' << tree[a].size() << ' ';
        sort(tree[a].begin(), tree[a].end());
        for(auto& c : tree[a])
            cout << c << ' ';
        cout << '\n';
    }
}

/*
    
*/