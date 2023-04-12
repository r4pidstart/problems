// https://www.acmicpc.net/problem/27925
// 2023-04-12 20:51:22
#include"bits/stdc++.h"
using namespace std;

int solution(int now, int a, int b, int c, vector<int>& arr, int init=0)
{
	static vector<vector<vector<vector<int> > > > 
		memo(init, vector<vector<vector<int> > >(10, vector<vector<int> >(10, vector<int>(10, -1))));

	if(now==memo.size()-1) return 0;
	if(memo[now][a][b][c]!=-1) return memo[now][a][b][c];

	return memo[now][a][b][c]=min({
				solution(now+1, arr[now+1], b, c, arr) + min((a-arr[now+1]+10)%10, (arr[now+1]-a+10)%10), 
				solution(now+1, a, arr[now+1], c, arr) + min((b-arr[now+1]+10)%10, (arr[now+1]-b+10)%10), 
				solution(now+1, a, b, arr[now+1], arr) + min((c-arr[now+1]+10)%10, (arr[now+1]-c+10)%10), 
				});
}

int main(void)
{
#ifdef LOCAL
#endif
	int n; scanf("%d", &n);
	vector<int> arr(n+1);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i+1]);
	printf("%d\n", solution(0, 0, 0, 0, arr, n+1));
}

/*
	
*/