// https://www.acmicpc.net/problem/17070
// 2021-08-20 21:27:53 0ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > field;
vector<vector<vector<int> > > memo; 
// 가로 대각선 세로

int dp(int x, int y, int r)
{
	if(memo[x][y][r]) return memo[x][y][r];

	int ret=0;
	if(field[x][y] || x==0 || y==0) return ret;

	if(r==0)
	{
		// 가로->가로
		ret+=dp(x,y-1,0);
		// 대각->가로
		ret+=dp(x,y-1,1);
	}
	else if(r==1 && !field[x-1][y] && !field[x][y-1])
	{
		// 가로->대각
		ret+=dp(x-1,y-1,0);
		// 대각->대각
		ret+=dp(x-1,y-1,1);
		// 세로->대각
		ret+=dp(x-1,y-1,2);
	}
	else if(r==2)
	{
		// 대각->세로
		ret+=dp(x-1,y,1);
		// 세로->세로
		ret+=dp(x-1,y,2);
	}
	return memo[x][y][r]=ret;
}

int main(void)
{
	int n; scanf("%d", &n);
	field.assign(n+1, vector<int>(n+1, 0));
	memo.assign(n+1, vector<vector<int> >(n+1, vector<int>(3,0)));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &field[i+1][j+1]);

	memo[1][2][0]=1; // initial state
	printf("%d", dp(n,n,0)+dp(n,n,1)+dp(n,n,2));
	return 0;
}

/*

*/