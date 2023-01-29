// https://www.acmicpc.net/problem/25381
// 2023-01-29 09:40:20
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	string s; cin >> s;
	
	vector<deque<int> > arr(3);
	for(int i=0; i<s.length(); i++)
		arr[s[i]-'A'].push_back(i);
	vector<deque<int> > arrcpy=arr;

	int cnt1=0;
	for(int i=0; i<arr[1].size(); i++) // b
	{
		while(arr[2].size() and arr[2].front() < arr[1][i]) arr[2].pop_front();

		if(arr[0].size() and arr[0].front() < arr[1][i])
			cnt1++, arr[0].pop_front();
		else if(arr[2].size())
			cnt1++, arr[2].pop_front();
	}

	arr=arrcpy;
	int cnt2=0;
	for(int i=0; i<arr[1].size(); i++) // b
	{
		while(arr[2].size() and arr[2].front() < arr[1][i]) arr[2].pop_front();

		if(arr[2].size())
			cnt2++, arr[2].pop_front();
		else if(arr[0].size() and arr[0].front() < arr[1][i])
			cnt2++, arr[0].pop_front();
	}
	
	printf("%d", max(cnt1, cnt2));
}

/*
	
*/