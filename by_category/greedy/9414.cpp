// https://www.acmicpc.net/problem/9414
// 2023-01-07 23:49:42
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int t; scanf("%d", &t);
	while(t--)
	{
		int n=0;
		vector<int> arr;
		while(true)
		{
			int tmp;
			scanf("%d", &tmp);
			if(tmp==0)
				break;
			else
				arr.push_back(tmp);
			n++;
		}
		sort(arr.begin(), arr.end(), greater<>());
		
		long ans=0;
		int flag=0;
		for(int i=0; i<n; i++)
		{
			if(2*pow(arr[i], i+1) >= 5*1e6)
				flag++;
			else
				ans+=2*pow(arr[i], i+1);
		}
		if(flag)
			printf("Too expensive\n");
		else
			printf("%ld\n", ans);
	}	
}

/*
	
*/