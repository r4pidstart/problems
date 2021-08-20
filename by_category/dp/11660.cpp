// https://www.acmicpc.net/problem/11660
// 2021-08-20 20:58:52 232ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n,m; scanf("%d%d", &n,&m);
	vector<vector<int> > num(n+1, vector<int>(n+1, 0));
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &num[i+1][j+1]);

	vector<vector<int> > sum(n+1, vector<int>(n+1, 0));
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+num[i][j];

	for(int i=0; i<m; i++)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
		printf("%d\n", sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1]);
	}
}

/*

*/