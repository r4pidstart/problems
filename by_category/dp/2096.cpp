// https://www.acmicpc.net/problem/2096
// 2021-08-20 20:38:36 28ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	vector<vector<int> > dpmin, dpmax;
	dpmin=dpmax=vector<vector<int> >(2, vector<int>(3, 0));
	
	for(int i=0; i<n; i++)
	{
		int a,b,c; scanf("%d%d%d", &a,&b,&c);
		if(i&1) // dp[0]
		{
			dpmax[0][0]=max(dpmax[1][0], dpmax[1][1])+a;
			dpmin[0][0]=min(dpmin[1][0], dpmin[1][1])+a;

			dpmax[0][1]=max({dpmax[1][0], dpmax[1][1], dpmax[1][2]})+b;
			dpmin[0][1]=min({dpmin[1][0], dpmin[1][1], dpmin[1][2]})+b;

			dpmax[0][2]=max(dpmax[1][1], dpmax[1][2])+c;
			dpmin[0][2]=min(dpmin[1][1], dpmin[1][2])+c;
		}
		else // dp[1]
		{
			dpmax[1][0]=max(dpmax[0][0], dpmax[0][1])+a;
			dpmin[1][0]=min(dpmin[0][0], dpmin[0][1])+a;

			dpmax[1][1]=max({dpmax[0][0], dpmax[0][1], dpmax[0][2]})+b;
			dpmin[1][1]=min({dpmin[0][0], dpmin[0][1], dpmin[0][2]})+b;

			dpmax[1][2]=max(dpmax[0][1], dpmax[0][2])+c;
			dpmin[1][2]=min(dpmin[0][1], dpmin[0][2])+c;
		}
	}
	if((n-1)&1)
		printf("%d %d", *max_element(dpmax[0].begin(), dpmax[0].end()), *min_element(dpmin[0].begin(), dpmin[0].end()));
	else
		printf("%d %d", *max_element(dpmax[1].begin(), dpmax[1].end()), *min_element(dpmin[1].begin(), dpmin[1].end()));

}

/*

*/