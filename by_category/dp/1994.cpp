// https://www.acmicpc.net/problem/1994
// 2024-03-26 15:12:07
#include"bits/stdc++.h"
using namespace std;

// int solution(int now, int dif, const vector<int>& arr)
// {
// 	// dp[now][dif]
// 	static vector<map<int, int> > dp(arr.size());
// 	if(now==arr.size()) return 0;
// 	if(dp[now].find(dif) != dp[now].end())
// 		return dp[now][dif];
	
// 	int ret=1;
// 	if(dif==INT32_MAX)
// 	{
// 		for(int i=now+1; i<arr.size(); i++)
// 			ret=max(ret, solution(i, arr[i]-arr[now], arr)+1);
// 	}
// 	else
// 	{
// 		auto it=lower_bound(arr.begin()+now+1, arr.end(), arr[now]+dif);
// 		if(it != arr.end() and *it==arr[now]+dif)
// 			ret=max(ret, solution(it-arr.begin(), dif, arr)+1);
// 	}
// 	return dp[now][dif]=ret;
// }

int solution(int now, int prev, const vector<int>& arr)
{
	static vector<vector<int> > dp(arr.size()+1, vector<int>(arr.size()+1, -1));
	if(prev!=-1 and dp[now][prev] != -1) return dp[now][prev];

	int ret=1;
	if(prev==-1)
	{
		for(int i=now+1; i<arr.size(); i++)
			ret=max(ret, solution(i, now, arr)+1);
	}
	else
	{
		int dif=arr[now]-arr[prev];
		auto it=lower_bound(arr.begin()+now+1, arr.end(), arr[now]+dif);
		if(it != arr.end() and *it==arr[now]+dif)
			ret=max(ret, solution(it-arr.begin(), now, arr)+1);
	}
	if(prev==-1)
		return ret;
	return dp[now][prev]=ret;
}

int main(void)
{
	int n; scanf("%d", &n);
	vector<int> arr(n);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	
	sort(arr.begin(), arr.end());

	int ans=0;
	for(int i=0; i<n; i++)
		// ans=max(ans, solution(i, INT32_MAX, arr));
		ans=max(ans, solution(i, -1, arr));

	printf("%d", ans);
}

/*
	
*/