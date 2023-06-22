// https://www.acmicpc.net/problem/10217
// 2023-06-21 03:27:09
#include "bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        vector<vector<tuple<int, int, int> > > graph(n + 1);
        for (int i = 0; i < k; i++)
        {
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            graph[a].push_back({b, c, d});
        }

        for(auto& v : graph)
            sort(v.begin(), v.end());

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<> > pq;
        vector<vector<int>> dist(n + 1, vector<int>(m + 1, INT32_MAX / 2));
        vector<pair<int, int> > min_dist(n + 1, {INT32_MAX, INT32_MAX});
        dist[1][0] = 0;
        pq.push({0, 0, 1});
        while (pq.size())
        {
            auto [d, c, now] = pq.top();
            pq.pop();

            if (dist[now][c] < d)
                continue;
            if (min_dist[now].first < d and min_dist[now].second < c)
                continue;

            for (auto &[next, nc, nd] : graph[now])
            {
                int ndist = d + nd, ncost = c + nc;
                if (ncost <= m and ndist < dist[next][ncost])
                {
                    dist[next][ncost] = ndist;
                    pq.push({ndist, ncost, next});
                    if (min_dist[next].first >= ndist and min_dist[next].second >= ncost)
                        min_dist[next] = {ndist, ncost};
                }
            }
        }
        int ans = *min_element(dist[n].begin(), dist[n].end());
        printf(ans ^ INT32_MAX / 2 ? "%d" : "Poor KCM", ans);
    }
}

/*

*/