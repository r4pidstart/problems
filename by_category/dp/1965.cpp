// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	vector<int> lis;
	for(int i=0; i<n; i++)
	{
		int a; scanf("%d", &a);
		auto it=lower_bound(lis.begin(), lis.end(), a);
		if(it==lis.end()) // 가장 큰 경우
			lis.push_back(a);
		else
			*it=a;
	}
	printf("%ld", lis.size());
}

/*

*/