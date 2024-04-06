// https://www.acmicpc.net/problem/2412
// 2024-03-23 15:55:56
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
	int n,t; scanf("%d%d", &n, &t);
	
	set<pair<int, int> > se;
	for(int i=0; i<n; i++)
	{
		int a,b; scanf("%d%d", &a, &b);
		se.insert({a, b});
	}
	map<pair<int, int>, int> dist;
	dist[{0, 0}]=1;
	queue<pair<int, int> > q;
	q.push({0, 0});

	while(q.size())
	{
		auto [x, y]=q.front();
		q.pop();

		if(y==t)
			return !printf("%d", dist[{x, y}]-1);
		for(int dx=-2; dx<=2; dx++)
			for(int dy=-2; dy<=2; dy++)
				if(se.find({x+dx, y+dy}) != se.end())
				{
					if(dist[{x+dx, y+dy}]==0)
						dist[{x+dx, y+dy}]=dist[{x,y}]+1, q.push({x+dx, y+dy});
				}		
	} 
	printf("-1");
}

/*
	
*/