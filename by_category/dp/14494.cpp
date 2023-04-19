// https://www.acmicpc.net/problem/14494
// 2023-04-20 03:22:08
#include"bits/stdc++.h"
using namespace std;

int dp(int x, int y)
{
	static vector<vector<int> > memo(x+1, vector<int>(y+1, -1));
	if(x==0 and y==0) return 1;
	else if(x<0 or y<0) return 0;
	if(memo[x][y] != -1) return memo[x][y];

	int ret=0;
	ret=(ret+dp(x-1, y))%((int)1e9+7);
	ret=(ret+dp(x-1, y-1))%((int)1e9+7);
	ret=(ret+dp(x, y-1))%((int)1e9+7);
	return memo[x][y]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
	int n,m; scanf("%d%d", &n, &m);
	printf("%d", dp(n-1, m-1));
}

/*
	
*/