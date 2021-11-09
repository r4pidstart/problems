// https://www.acmicpc.net/problem/17827
// 2021-11-10 02:25:30 C
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n,m,v; scanf("%d%d%d", &n,&m,&v);
	vector<int> arr(n+1);
	for(int i=1; i<=n; i++) scanf("%d", &arr[i]);

	while(m--)
	{
		int target; scanf("%d", &target);
		target++;

		if(target <= n) printf("%d\n", arr[target]);
		else
		{
			// n -> v -> n -> v
			target-=v;
			target%=(n-v)+1;
			printf("%d\n", arr[target+v]);
		}
	}
}

/*
	
*/