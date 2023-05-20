// https://www.acmicpc.net/problem/27312
// 2023-05-21 00:30:17
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int m,n,q; scanf("%d%d%d", &m, &n, &q);
	vector<int> arr(n);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	
	vector<int> ans(n);
	for(int i=0; i<m; i++)
	{
		printf("? %d %d\n", i+1, i+1);
		fflush(stdout);
		scanf("%d", &ans[i]);
	}

	printf("! ");
	for(int i=0; i<n; i++)
		printf("%d ", (ans[i])%arr[i]+1);
}

/*
	
*/