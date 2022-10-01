// https://www.acmicpc.net/problem/15688
// 2022-10-02 01:14:27 6660ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	vector<int> arr(n);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());
	for(auto &i : arr)
		printf("%d\n", i);
}

/*
	
*/