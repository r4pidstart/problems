// https://www.acmicpc.net/problem/17954
// 2021-11-09 02:34:25 H
#include<bits/stdc++.h>
using namespace std;

int main(void)
{	
	int n; scanf("%d", &n);
	if(n==1) return !printf("2\n1\n2");
	long long ans=0;
	deque<int> arr1, arr2;
	int sum1=0, sum2=0;

	arr1.push_back(2*n);
	sum1+=2*n;
	for(int i=1; i<n-1; i++)
	{
		arr1.push_front(i);
		sum1+=i;
	}
	arr1.push_front(2*n-1);
	sum1+=2*n-1;

	arr2.push_back(2*n-2);
	sum2+=2*n-2;
	for(int i=n-1; i<2*n-3; i++)
	{
		arr2.push_front(i);
		sum2+=i;
	}
	arr2.push_front(2*n-3);
	sum2+=2*n-3;

	for(int i=0; i<n; i++)
	{
		sum2-=arr2[i];
		ans+=(sum2+sum1)*(long long)(i+1);
	}
	for(int i=0; i<n; i++)
	{
		sum1-=arr1[i];
		ans+=(sum1+sum2)*(long long)(i+n+1);
	}

	printf("%lld\n", ans);
	for(int& i : arr1) printf("%d ", i);
	printf("\n");
	for(int& i : arr2) printf("%d ", i);
}

/*
	15 6 5 4 3 2 1 16
	13 12 11 10 9 8 7 14
*/