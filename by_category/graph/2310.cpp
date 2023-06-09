// https://www.acmicpc.net/problem/2310
// 2023-06-10 03:34:02
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    while(n)
    {
        vector<pair<int, int> > table(n+1);
        vector<vector<int> > graph(n+1);
        for(int i=0; i<n; i++)
        {
            char t; int k;
            scanf(" %c %d", &t, &k);
            table[i+1]={t, k};

            int m; scanf("%d", &m);
            while(m)
            {
                graph[i+1].push_back(m);
                scanf("%d", &m);
            }
        }

        queue<pair<int, int> > q;
        vector<vector<int> > visited(n+1, vector<int>(501));
        q.push({1, 0});
        visited[1][0]=1;

        while(q.size())
        {
            auto [now, money]=q.front();
            q.pop();
            
            if(now==n)
            {
                printf("Yes\n");
                goto while_end;
            }

            for(int next : graph[now])
            {
                if(table[next].first=='E' and !visited[next][money]) 
                    q.push({next, money}), visited[next][money]=1;
                else if(table[next].first=='L' and !visited[next][max(table[next].second, money)])
                    q.push({next, max(table[next].second, money)}), visited[next][max(table[next].second, money)]=1;
                else if(table[next].first=='T' and money-table[next].second>=0 and !visited[next][money-table[next].second])
                    q.push({next, money-table[next].second}), visited[next][money-table[next].second]=1;
            }
        }

        printf("No\n");
        while_end:

        scanf("%d", &n);
    }
}

/*
    
*/