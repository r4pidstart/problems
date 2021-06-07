// https://www.acmicpc.net/problem/3665
// 2021-06-05 02:20:30 40ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        
        vector<vector<int> > edge(n+1);
        vector<int> p_rank(n+1), rank(n+1), in_degree(n+1, 0);

        for(int i=1; i<=n; i++)
        {
            scanf("%d", &p_rank[i]);
            rank[p_rank[i]]=i;
            in_degree[p_rank[i]]=i-1;
        }

        for(int i=1; i<n; i++)
            for(int j=i+1; j<=n; j++)
                edge[p_rank[i]].push_back(p_rank[j]);
        

        int m; scanf("%d", &m);
        for(int i=0; i<m; i++)
        {
            int a,b; scanf("%d%d", &a,&b);
            if(rank[b]<rank[a]) // b팀 등수가 더 높을 때
            {
                edge[b].erase(find(edge[b].begin(), edge[b].end(), a));
                edge[a].push_back(b);
                in_degree[a]--, in_degree[b]++;
            }
            else
            {
                edge[a].erase(find(edge[a].begin(), edge[a].end(), b));
                edge[b].push_back(a);
                in_degree[b]--, in_degree[a]++;
            }
        }

        queue<int> q;
        for(int i=1; i<=n; i++)
            if(in_degree[i]==0)
                q.push(i);

        deque<int> ans;
        for(int i=1; i<=n; i++)
        {
            if(q.empty()) // 사이클 발생
                break;
            int now=q.front();
            ans.push_back(now);
            q.pop();

            for(int next : edge[now])
                if((--in_degree[next])==0)
                    q.push(next);
        }

        if(ans.size()!=n)
            printf("IMPOSSIBLE"); // 사이클 발생
        else
            for(int i : ans)
                printf("%d ", i);
        printf("\n");
    }
}