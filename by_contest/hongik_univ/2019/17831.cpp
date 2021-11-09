// https://www.acmicpc.net/problem/17831
// 2021-11-10 04:52:55 I
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
vector<vector<long long> > memo; // memo[i][0,1]
vector<int> value;

long long dp(int n, int skip)
{
	if(graph[n].size()==0)
		return 0;

	if(memo[n][skip]!=-1) return memo[n][skip];

	long long& ret=memo[n][skip]=0;

	if(skip)
	{
		for(int& next : graph[n])
		{
			long long tmpret=0;
			tmpret=max(tmpret, dp(next,0)); // 다음걸 고른 경우
			tmpret=max(tmpret, dp(next,1)); // 다음것도 안 고른 경우
			ret+=tmpret;
		}
		return ret;
	}

	// 어느 것을 이을 건지
	// 지금을 완전히 버리는 경우
	for(int& next : graph[n])
	{
		long long tmpret=0;
		tmpret=max(tmpret, dp(next,0)); // 지금을 버리는 경우
		tmpret=max(tmpret, dp(next,1)); // 지금과 다음을 버리는 경우
		ret+=tmpret;
	}

	long long tmpret=0;
	long long psum=ret;
	// 하나만 지금걸 사용해서 잇는 경우
	for(int& next : graph[n])
	{
		// 선택된 정점을 사용하는 경우만 뺌
		ret=max(ret, psum -max(dp(next,0), dp(next,1)) +dp(next,1)+value[n]*value[next]);
	}
	return ret;
}

int main(void)
{
	int n; scanf("%d", &n);
	graph.assign(n+1,{});
	value.assign(n+1,0);
	memo.assign(n+1, vector<long long>(2,-1)); 
	for(int i=2; i<=n; i++)
	{
		int a; scanf("%d", &a);
		graph[a].push_back(i);
	}
	for(int i=1; i<=n; i++) scanf("%d", &value[i]);

	printf("%lld", dp(1,0));
	return 0;
}

/*
	
*/