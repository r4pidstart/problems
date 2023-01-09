// https://www.acmicpc.net/problem/22971
// 2023-01-10 03:06:53
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int n; scanf("%d", &n);
	vector<int> arr(n+1);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i+1]);
	vector<int> dp(n+1);
	dp[0]=1;
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<i; j++)
			if(arr[j] < arr[i])
				dp[i]=(dp[i]+dp[j])%998'244'353;
	}
	for(int i=1; i<=n; i++)
		printf("%d ", dp[i]);
}

/*
	
*/