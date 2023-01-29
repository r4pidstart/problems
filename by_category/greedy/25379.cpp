// https://www.acmicpc.net/problem/25379
// 2023-01-29 09:07:20
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int n; scanf("%d", &n);
	vector<int> arr(n);

	for(int i=0; i<n; i++)	
		scanf("%d", &arr[i]);
	
	// 홀수부터
	long ansa=0, cnta=0;
	for(int i=0; i<n; i++)
	{
		if(arr[i]&1)
			ansa+=(i-cnta), cnta++;
	}

	// 짝수부터
	long ansb=0, cntb=0;
	for(int i=0; i<n; i++)
	{
		if(!(arr[i]&1))
			ansb+=(i-cntb), cntb++;
	}
	printf("%ld", min(ansa, ansb));
}

/*
	
*/