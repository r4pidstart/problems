// https://www.acmicpc.net/problem/17829
// 2021-11-10 02:55:13 E
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > arr;

int dc(int n, int x, int y)
{
	if(n==2)
	{
		vector<int> tmp={arr[x][y], arr[x+1][y], arr[x][y+1], arr[x+1][y+1]};
		sort(tmp.begin(), tmp.end());
		return tmp[2];
	}
	else
	{
		vector<int> tmp{dc(n/2, x,y), dc(n/2, x+n/2,y), dc(n/2, x,y+n/2), dc(n/2, x+n/2,y+n/2)};
		sort(tmp.begin(), tmp.end());
		return tmp[2];
	}
}

int main(void)
{
	int n; scanf("%d", &n);
	arr.assign(n, vector<int>(n,0));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &arr[i][j]);

	printf("%d", dc(n,0,0));
}

/*
	
*/