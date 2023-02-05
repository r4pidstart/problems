// https://www.acmicpc.net/problem/1774
// 2023-02-06 01:29:04
#include"bits/stdc++.h"
using namespace std;

vector<int> parent;

int find(int a)
{
	if(parent[a]<0)
		return a;
	return parent[a]=find(parent[a]);
}

int merge(int a, int b)
{
	a=find(a), b=find(b);
	if(a==b)
		return 1;

	if(parent[a] > parent[b])
		swap(a,b);
	parent[a]+=parent[b];
	parent[b]=a;
	return 0;
}

double get_dist(pair<int,int> &a, pair<int,int> &b)
{
	return sqrt((long)(a.first-b.first)*(a.first-b.first) 
		+ (long)(a.second-b.second)*(a.second-b.second));
}

int main(void)
{
#ifdef LOCAL
#endif
	int n,m; scanf("%d%d", &n, &m);
	vector<pair<int,int> > coord(n);
	for(int i=0; i<n; i++)
		scanf("%d %d", &coord[i].first, &coord[i].second);
	parent.assign(n, -1);
	for(int i=0; i<m; i++)
	{
		int a,b; scanf("%d%d", &a, &b);
		merge(a-1,b-1);
	}	

	vector<pair<double, pair<int, int> > > graph;
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			graph.push_back({get_dist(coord[i], coord[j]), {i, j}});
	sort(graph.begin(), graph.end());

	int idx=0;
	double ans=0;
	while(-parent[find(0)] != n)
	{
		if(!merge(graph[idx].second.first, graph[idx].second.second))
			ans+=graph[idx].first;
		idx++;
	}
	printf("%.2lf", ans);
}

/*
	
*/