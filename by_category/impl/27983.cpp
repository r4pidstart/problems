// https://www.acmicpc.net/problem/27983
// 2023-05-10 21:47:17
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int n; scanf("%d", &n);
	vector<tuple<int,int,int> > arr(n);
	for(int i=0; i<n; i++)
		scanf("%d", &get<0>(arr[i]));
	for(int i=0; i<n; i++)
		scanf("%d", &get<1>(arr[i]));
	for(int i=0; i<n; i++)
		scanf(" %c", &get<2>(arr[i]));
	
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
		{
			auto& [x1, l1, c1]=arr[i];
			auto& [x2, l2, c2]=arr[j];

			if(abs(x1-x2)<=l1+l2 and c1!=c2)
				return !printf("YES\n%d %d", i+1, j+1);
		}
	printf("NO");
}

/*
	
*/