// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

long ans(int i, int j, vector<int>& a, vector<int>& b, vector<vector<int> >& table)
{
	static vector<vector<long> > dp(i+1, vector<long>(j+1, -1));

	if(i<=0 or j<=0)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	
	long ret=0;
	ret=max(ret, ans(i-1, j, a, b, table));
	ret=max(ret, ans(i, j-1, a, b, table));
	ret=max(ret, ans(i-1, j-1, a, b, table)+max(table[a[i-1]-1][b[j-1]-1], table[b[j-1]-1][a[i-1]-1]));

	return dp[i][j]=ret;
}
int main(void)
{
#ifdef LOCAL
#endif
	int n,m,c; scanf("%d%d%d", &n, &m, &c);
	vector<vector<int> > table(c, vector<int>(c));
	for(int i=0; i<c; i++)
		for(int j=0; j<c; j++)
			scanf("%d", &table[i][j]);
	
	vector<int> univA(n), univB(m);

	for(int i=0; i<n; i++)
		scanf("%d", &univA[i]);
	for(int j=0; j<m; j++)
		scanf("%d", &univB[j]);

	printf("%ld", ans(n, m, univA, univB, table));
}

/*
	
*/