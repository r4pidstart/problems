// https://www.acmicpc.net/problem/5214
// 2021-11-09 03:11:23 280ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n,k,m; scanf("%d%d%d", &n,&k,&m);
	vector<vector<int> > graph(n+1+m);
	for(int i=n+1; i<n+1+m; i++)
	{
		for(int j=0; j<k; j++) 
		{
			int target; scanf("%d", &target);
			graph[target].push_back(i);
			graph[i].push_back(target);
		}
	}

	// 1 to n
	if(n==1) return !printf("1");
	vector<int> visited(n+1+m);
	queue<pair<int,int> > q;
	// dist, now
	q.push({1,1});
	while(!q.empty())
	{
		pair<int,int> pii=q.front(); q.pop();
		if(visited[pii.second]) continue;
		visited[pii.second]=1;
		if(pii.second==n) return !printf("%d", pii.first+1);
		for(int& next : graph[pii.second])
			if(!visited[next]) q.push({pii.first+(next < n), next});
	}
	printf("-1");
}

/*
	
*/