// https://www.acmicpc.net/problem/14718
// 2024-03-25 22:07:41
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
	int n,t; scanf("%d%d", &n, &t);
	vector<tuple<int, int, int> > arr(n);
	for(int i=0; i<n; i++)
	{
		int a,b,c; scanf("%d%d%d", &a, &b, &c);
		arr[i]={a, b, c};
	}
	
	int ans=INT32_MAX;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++)
			{
				int a=get<0>(arr[i]), b=get<1>(arr[j]), c=get<2>(arr[k]);
				int cnt=0;
				for(auto [x, y, z] : arr)
					if(x<=a and y<=b and z<=c) cnt++;
				
				if(cnt >= t)
					ans=min(ans, a+b+c);
			}
	printf("%d", ans);
}

/*
	
*/