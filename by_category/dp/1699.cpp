// https://www.acmicpc.net/problem/1699
// 2021-08-16 23:24:07 56ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);

	// n 이하의 제곱 수 구하기
	vector<int> squares;
	for(int i=1; i*i<=n; i++)
		squares.push_back(i*i);

	vector<int> dp(n+1, INT32_MAX);
	dp[0]=0;
	for(int i=1; i<=n; i++)
	{
		for(int sq : squares)
		{
			if(i-sq<0) break;
			dp[i]=min(dp[i], dp[i-sq]+1);
		}
	}
	printf("%d", dp[n]);
}

/*

*/