// https://www.acmicpc.net/problem/14471
// 2022-04-28 19:54:12 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n,m; scanf("%d%d", &n, &m);
	vector<int> arr(m);
	for(int i=0; i<m; i++)
	{
		int a,b; scanf("%d%d", &a, &b);
		arr[i]=max(0, b-n);
	}
	sort(arr.begin(), arr.end());
	printf("%d", accumulate(arr.begin(), arr.end()-1, 0));

}

/*
	
*/