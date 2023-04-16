// https://www.acmicpc.net/problem/1239
// 2023-04-16 23:11:36
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int n; scanf("%d", &n);
	vector<int> arr(n);
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());

	int ans=0;
	do
	{
		vector<int> psum(n+1);
		for(int i=1; i<=n; i++)
			psum[i]=psum[i-1]+arr[i-1];
		
		int tmp=0;
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++)
				if(psum[i]+50 == psum[j]) tmp++;
		ans=max(tmp, ans);
	}
	while(next_permutation(arr.begin(), arr.end()));
	printf("%d", ans);
}

/*
	
*/