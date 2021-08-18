// https://www.acmicpc.net/problem/2225
// 2021-08-19 02:51:40 20ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > memo;

int dp(int n, int k)
{
	if(k==1) return 1;

	if(memo[n][k]) return memo[n][k];
	
	int ret=0;
	for(int i=0; i<=n; i++)
		ret=(ret+dp(n-i, k-1))%1'000'000'000;
	
	return memo[n][k]=ret;
}

int main(void)
{
	int n,k; scanf("%d%d", &n,&k);
	memo.assign(n+1, vector<int>(k+1, 0));
	printf("%d", dp(n,k));

}

/*

*/