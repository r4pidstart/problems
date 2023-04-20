// https://www.acmicpc.net/problem/9694
// 2023-04-20 19:06:18
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int t; scanf("%d", &t);
	for(int T=1; T<=t; T++)
	{
		int n,m; scanf("%d%d", &n, &m);
		vector<vector<pair<int,int> > > graph(m);
		for(int i=0; i<n; i++)
		{
			int a,b,c; scanf("%d%d%d", &a, &b, &c);
			graph[a].push_back({b, c});
			graph[b].push_back({a, c});
		}

		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
		vector<int> dist(m, INT32_MAX/2), prev(m, -1);
		dist[0]=0;
		pq.push({0, 0});
		while(pq.size())
		{
			auto [nowdist, now]=pq.top();
			pq.pop();

			if(dist[now] < nowdist) continue;

			for(auto next : graph[now])
			{
				int ndist=nowdist+next.second;
				if(dist[next.first] > ndist)
				{
					prev[next.first]=now;
					dist[next.first]=ndist;
					pq.push({ndist, next.first});
				}
			}
		}
		printf("Case #%d: ", T);
		if(dist[m-1] == INT32_MAX/2) printf("-1\n");
		else
		{
			stack<int> stk;
			int cur=m-1;
			while(cur != -1)
			{
				stk.push(cur);
				cur=prev[cur];
			}
			while(stk.size())
				printf("%d ", stk.top()), stk.pop();
			printf("\n");
		}
	}
}

/*
	
*/