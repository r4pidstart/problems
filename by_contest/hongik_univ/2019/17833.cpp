// https://www.acmicpc.net/problem/17833
// 2021-11-11 05:04:38 272ms
#include<bits/stdc++.h>
using namespace std;

#define ll long long
struct Building
{
	int height, time, in, out;
};

int main(void)
{
	int n; scanf("%d", &n);
	int s,e; scanf("%d%d", &s, &e);
	int m; scanf("%d", &m);
	vector<Building> building;
	for(int i=0; i<m; i++) 
	{
		int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
		building.push_back({a,b,c,d});
		building.push_back({a,b,d,c});
	}

	vector<ll> dist(n+1,LLONG_MAX/2); 
	priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
	dist[s]=0;
	pq.push({0,s});
	while(!pq.empty())
	{
		auto now=pq.top(); pq.pop();
		if(now.first > dist[now.second]) continue;
		
		// 모든 경우의 수를 넣어보기
		for(auto& it : building)
		{
			// 가능한 경우인지 체크
			if(now.second - it.in >= 0 and now.second+(it.height-it.in) <= n)
			{
				ll ndist=now.first + it.time, nfloor=now.second + (it.out-it.in);
				if(ndist < dist[nfloor])
				{
					pq.push({ndist, nfloor});
					dist[nfloor]=ndist;
				}
			}
		}
	}
	printf("%lld", dist[e]!=LLONG_MAX/2 ? dist[e]:-1);
}

/*
	
*/