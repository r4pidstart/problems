// https://www.acmicpc.net/problem/13144
// 2022-10-06 02:27:25 16ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	vector<int> arr(n), duplicated(100001);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	
	int l=0, h=-1;
	long ans=0;
	while(h<n)
	{
		ans+=h-l+1;
		if(h+1<n)
		{
			duplicated[arr[h+1]]++;
			while(duplicated[arr[h+1]] > 1)
				duplicated[arr[l++]]--;
		}
		h++;
	}
	printf("%ld", ans);
}

/*
	
*/