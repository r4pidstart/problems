// https://www.acmicpc.net/problem/17835
// 2021-11-10 03:40:01 G
#include<bits/stdc++.h>
using namespace std;

struct Input
{
	int a,b,c;
};

int main(void)
{
	// 면접장을 하나로 뭉쳐보자

	int n,m,k; scanf("%d%d%d", &n,&m,&k);
	vector<vector<pair<int,int> > > graph(n+1, vector<pair<int,int> >()); // 면접장 == 0번 노드
	vector<Input> input(m);
	for(int i=0; i<m; i++) scanf("%d%d%d", &input[i].a, &input[i].b, &input[i].c);
	vector<int> dest(n+1); // 면접장인지
	for(int i=0; i<k; i++)
	{
		int a; scanf("%d", &a);
		dest[a]=1;
	}

	for(int i=0; i<m; i++) 
	{
		if(dest[input[i].a]) continue;
		else if(dest[input[i].b]) // a to b -> b to a로 변형
			graph[0].push_back({input[i].a, input[i].c});
		else
			graph[input[i].b].push_back({input[i].a, input[i].c});
	}

	// dijkstra
	vector<long long> dist(n+1, LLONG_MAX/2);
	priority_queue<pair<long long,long long>, vector<pair<long long,long long> >, greater<pair<long long,long long> > > pq;
	pq.push({0,0}); // 면접장에서 다른 집으로 dist, now
	dist[0]=0;
	while(!pq.empty())
	{
		auto now=pq.top(); pq.pop();
		// 면접장에선 다른 집으로 갈 필요가 없음
		// if(dest[now.second]) continue;
		if(now.first > dist[now.second]) continue;
		for(auto& next : graph[now.second])
		{
			long long ndist=now.first+next.second;
			if(ndist < dist[next.first])
			{
				dist[next.first]=ndist;
				pq.push({ndist, next.first});
			}
		}
	}

	long long ansDist=0, ansPoint=1; // 전부 면접장이면 1번 
	for(int i=1; i<=n; i++)
	{
		if(ansDist < dist[i] and dist[i]!=LLONG_MAX/2)
		{
			ansDist=dist[i];
			ansPoint=i;
		}
	}
	printf("%lld\n%lld", ansPoint, ansDist);
}

/*
	
*/