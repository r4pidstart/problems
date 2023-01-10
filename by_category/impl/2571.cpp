// https://www.acmicpc.net/problem/2571
// 2023-01-11 00:50:44
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	vector<vector<int> > table(100, vector<int>(100));
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++)	
	{
		int a,b; scanf("%d%d", &a, &b);
		for(int x=a; x<a+10; x++)
			for(int y=b; y<b+10; y++)
				table[x][y]=1;
	}

	vector<vector<int> > psum(101, vector<int>(101));
	for(int i=1; i<=100; i++)
		for(int j=1; j<=100; j++)
			psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+table[i-1][j-1];
	
	int ans=0;
	for(int a=1; a<=100; a++)
		for(int b=1; b<=100; b++)
			for(int x=a; x<=100; x++)
				for(int y=b; y<=100; y++)
				{
					// int flag=0;
					// for(int i=a; i<=x; i++)
					// {
					// 	if(flag)
					// 		break;
					// 	for(int j=b; j<=y; j++)
					// 		if(!table[i-1][j-1]) 
					// 		{
					// 			flag++;
					// 			break;
					// 		}
					// }
					// if (!flag)
					// 	ans=max(ans, (x-a+1)*(y-b+1));
					if(psum[x][y]-psum[a-1][y]-psum[x][b-1]+psum[a-1][b-1] == (x-a+1)*(y-b+1))
						ans=max(ans, (x-a+1)*(y-b+1));
				}
	printf("%d", ans);
}

/*
	
*/