// https://www.acmicpc.net/problem/10159
// 2022-04-12 23:55:17 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > graph_bigger(n+1), graph_smaller(n+1);

    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph_bigger[a].push_back(b);
        graph_smaller[b].push_back(a);
    }

    // bfs로 각 정점에서 도달가능한 모든 정점의 갯수를 센다
    // 모순이 없으니까 다 되겠지
    for(int i=1; i<=n; i++)
    {
        queue<int> q;
        vector<int> visited1(n+1);
        vector<int> visited2(n+1);
        q.push(i);
        while(!q.empty())
        {
            int now=q.front(); q.pop();
            if(visited1[now])
                continue;
            visited1[now]=1;

            for(auto next : graph_smaller[now])
                q.push(next);
        }

        q.push(i);
        while(!q.empty())
        {
            int now=q.front(); q.pop();
            if(visited2[now])
                continue;
            visited2[now]=1;

            for(auto next : graph_bigger[now])
                q.push(next);
        }

        int cnt=n;
        for(int i=1; i<=n; i++)
            cnt-=visited1[i]|visited2[i];
        printf("%d\n", cnt);
    }
}

/*
    
*/