// https://www.acmicpc.net/problem/11722
// 2021-08-19 00:05:23 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	vector<int> dp(n,0);
	vector<int> num(n,0);
	for(int i=0; i<n; i++)
		scanf("%d", &num[i]);

	for(int i=0; i<n; i++)
	{
		int tmp=1;
		for(int j=0; j<i; j++)
			if(num[j]>num[i])
				tmp=max(dp[j]+1, tmp);
		dp[i]=tmp;
	}
	printf("%d", *max_element(dp.begin(), dp.end()));
}

/*

*/