// https://www.acmicpc.net/problem/26095
// 2022-12-04 02:14:28
#include"bits/stdc++.h"
using namespace std;

const int MAX=300001;
int check(int mid, const vector<int>& arr)
{
	__int128_t offset=0, remain=0;
	for(int i=MAX-1; i>1; i--)
	{
		if(arr[i] < offset)
			offset+=offset-arr[i];
		else if(arr[i] > offset)
			remain+=arr[i]-offset;

		if(offset > 1000000)
			return 0;
		if(i==mid) offset=1;
	}
	return !(arr[1]+remain<2*offset);
}

int main(void)
{
#ifdef LOCAL
#endif
	int n; scanf("%d", &n);
	vector<int> arr(MAX);

	for(int i=0; i<n; i++)
	{
		int a; scanf("%d", &a);
		arr[a]++;
	}
	arr[1]+=arr[0];

	int lo=0, hi=n, ans=0;
	while(lo<=hi)
	{
		int mid=(lo+hi)/2;
		if(check(mid, arr))
		{
			ans=mid;
			lo=mid+1;
		}
		else
			hi=mid-1;
	}
	printf("%d", ans);
}

/*
	
*/