// https://www.acmicpc.net/problem/2660
// 2023-10-11 02:19:28
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<vector<int> > graph(n+1);
    int a,b; scanf("%d%d", &a, &b);
    while(a!=-1 or b!=-1)
    {
        graph[a].push_back(b);
        graph[b].push_back(a);
        scanf("%d%d", &a, &b);
    }

    int min_cnt=INT32_MAX;
    vector<int> cand;

    for(int i=1; i<=n; i++)
    {
        queue<int> q;
        vector<int> dist(n+1, INT32_MAX/2);
        dist[i]=0;
        q.push(i);

        while(q.size())
        {
            int now=q.front();
            q.pop();

            for(int next : graph[now])
            {
                if(dist[next] > dist[now]+1)
                    dist[next]=dist[now]+1, q.push(next);
            }
        }

        int max_cnt=*max_element(dist.begin()+1, dist.end());
        if(max_cnt < min_cnt)
            min_cnt=max_cnt, cand.assign(1, i);
        else if(max_cnt == min_cnt)
            cand.push_back(i);
    }
    printf("%d %d\n", min_cnt, cand.size());
    for(int i : cand)
        printf("%d ", i);
}

/*
    
*/