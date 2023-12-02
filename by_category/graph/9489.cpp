// https://www.acmicpc.net/problem/9489 
// 2023-11-30 14:31:45
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,k;
    while(scanf("%d%d", &n, &k))
    {
        if(n==0 and k==0)
            break;

        map<int, vector<int>> graph;
        map<int, int> parent;
        queue<int> q;

        int prev=0;
        q.push(0);
        for(int i=0; i<n; i++)
        {
            int a; scanf("%d", &a);
            if(i and a!=prev+1) // go to next node
                q.pop();
            
            graph[q.front()].push_back(a);
            parent[a]=q.front();
            q.push(a);
            prev=a;
        }

        int ans=0;
        for(auto target : graph[parent[parent[k]]])
            if(target != parent[k])
                ans+=graph[target].size();
        printf("%d\n", ans);
    }
}

/*
    
*/