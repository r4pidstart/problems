// https://www.acmicpc.net/problem/1813
// 2022-04-28 19:32:26 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	vector<int> arr(n);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	sort(arr.begin(), arr.end());
	for(int i=50; i; i--)
	{
		if(upper_bound(arr.begin(), arr.end(), i) - lower_bound(arr.begin(), arr.end(), i) == i)
			return !printf("%d", i);
	}
	if(arr.front() == 0)
		printf("-1");
	else
		printf("0");
}

/*
	
*/