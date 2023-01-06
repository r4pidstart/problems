// https://www.acmicpc.net/problem/17176
// 2023-01-06 21:55:36
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int n; scanf("%d", &n);
	vector<int> arr(127);
	for(int i=0; i<n; i++)
	{
		int a; scanf("%d", &a);
		if(a==0)
			arr[' ']++;
		else if(a<27)
			arr[a-1+'A']++;
		else
			arr[a-27+'a']++;
	}

	cin.ignore();
	string s; getline(cin, s);
	for(int i=0; i<s.length(); i++)
	{
		if(arr[s[i]])
			arr[s[i]]--;
		else
			return !printf("n");
	}
	printf("y");
}

/*
	
*/