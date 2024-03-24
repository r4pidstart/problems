// https://www.acmicpc.net/problem/3908
// 2024-03-22 21:55:23
#include"bits/stdc++.h"
using namespace std;

int solution(int n, int k, int i, const vector<int>& primes)
{
	static vector<vector<vector<int> > > dp(1121, vector<vector<int> >(15, vector<int>(primes.size()+1, -1)));
	if(n==0)
		return !k;
	if(i==primes.size())
		return 0;
	if(dp[n][k][i] != -1)
		return dp[n][k][i];

	int ret=solution(n, k, i+1, primes);
	if(k and n-primes[i]>=0)
		ret+=solution(n-primes[i], k-1, i+1, primes);

	return dp[n][k][i]=ret;
}

int main(void)
{
	vector<int> primes;
	for(int i=2; i<1121; i++)
	{
		int flag=0;
		for(int j=2; j<i; j++)
			if(i%j==0) flag++;
		if(!flag) 
			primes.push_back(i);
	}
	int t; scanf("%d", &t);
	while(t--)
	{
		int a,b; scanf("%d%d", &a, &b);
		printf("%d\n", solution(a, b, 0, primes));
	}
}

/*
	
*/