// https://www.acmicpc.net/problem/28115
// 2023-05-21 12:38:09
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int n; scanf("%d", &n);
	int arr[n+1];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	
	int prev=arr[1]-arr[0], flag=0;
	for(int i=1; i<n; i++)
		if(prev != arr[i]-arr[i-1]) flag=1;
	if(flag) printf("NO\n");
	else
	{
		printf("YES\n");
		for(int i=0; i<n; i++)
			printf("%d ", arr[i]);
		printf("\n");
		for(int i=0; i<n; i++)
			printf("0 ");
	}
}