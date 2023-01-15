// https://www.acmicpc.net/problem/27210
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int n; scanf("%d", &n);
	vector<int> arr(n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
		if(arr[i]==2) arr[i]=-1;
	}

	vector<int> psum(n+1);
	for(int i=1; i<=n; i++)
		psum[i]=psum[i-1]+arr[i-1];
	
	sort(psum.begin(), psum.end());
	int lo=0, hi=n, ans=0;
	while(lo!=hi)
	{
		if(abs(psum[hi]-psum[lo]) > ans)
		{
			ans=abs(psum[hi]-psum[lo]);
		}
		if(psum[hi]-psum[lo] < 0) lo++;
		else hi--;
	}
	printf("%d", ans);
}

/*
	
*/