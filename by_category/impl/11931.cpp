// https://www.acmicpc.net/problem/11931
// 2023-01-13 04:26:12
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
	sort(arr.begin(), arr.end(), greater<>());
	for(auto i : arr)
		printf("%d\n", i);	
}

/*
	
*/