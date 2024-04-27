// https://www.acmicpc.net/problem/2479
// 2024-04-26 12:11:45
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++)
    {
        string s; cin >> s;
        arr[i]=stoi(s, 0, 2);
    }

    vector<vector<int> > graph(n+1);
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            if(__builtin_popcount(arr[i]^arr[j])==1)
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
    
    int s,e; scanf("%d%d", &s, &e);
    vector<int> prev(n+1, -1);
    queue<int> q;
    q.push(s);
    prev[s]=0;
    while(q.size())
    {
        int now=q.front();
        q.pop();

        for(int next : graph[now])
            if(prev[next] == -1)
                prev[next]=now, q.push(next);
    }

    if(prev[e]==-1)
        printf("-1");
    else
    {
        vector<int> ans;
        int cur=e;
        while(cur)
            ans.push_back(cur), cur=prev[cur];
        reverse(ans.begin(), ans.end());
        for(int i : ans)
            printf("%d ", i);
    }

}

/*
    
*/