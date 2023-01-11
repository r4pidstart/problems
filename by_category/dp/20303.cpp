// https://www.acmicpc.net/problem/20303
// 2023-01-12 02:40:10
#include"bits/stdc++.h"
using namespace std;

pair<int,int> dfs(int now, vector<vector<int> >& graph, vector<int> &visited, vector<int> &arr)
{
	visited[now]=1;

	// people, candy
	pair<int,int> ret={1, arr[now]};
	for(auto next : graph[now])
	{
		if(!visited[next])
		{
			visited[next]=1;
			auto tmp=dfs(next, graph, visited, arr);
			ret.first+=tmp.first;
			ret.second+=tmp.second;
		}
	}
	return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
	int n,m,k; scanf("%d%d%d", &n, &m, &k);
	vector<vector<int> > graph(n+1);
	vector<int> arr(n+1);

	for(int i=1; i<=n; i++)
		scanf("%d", &arr[i]);
	
	for(int i=0; i<m; i++)
	{
		int a,b; scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	// people, candy
	vector<pair<int,int> > candy;
	vector<int> visited(n+1);
	for(int i=1; i<=n; i++)
	{
		if(!visited[i])
			candy.push_back(dfs(i, graph, visited, arr));
	}

	// knapsack
	vector<int> dp(k+1);
	for(int i=1; i<=candy.size(); i++)
		for(int j=k-1; j>0; j--)
		{
			if(j-candy[i-1].first >= 0)
				dp[j]=max(dp[j], dp[j-candy[i-1].first] + candy[i-1].second);
		}
	printf("%d", dp[k-1]);
}

/*
	
*/