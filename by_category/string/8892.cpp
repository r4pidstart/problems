// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int is_palindrome(string s)
{
	int cur1=0, cur2=s.length()-1;
	while(cur1 <= cur2)
	{
		if(s[cur1]!=s[cur2]) return 0;
		cur1++, cur2--;
	}	
	return 1;
}

int bruteforce(vector<string>& arr)
{
	for(int i=0; i<arr.size(); i++)
			for(int j=0; j<arr.size(); j++)
			{
				if(i==j) continue;
				if(is_palindrome(arr[i]+arr[j]))
				{
					cout << arr[i]+arr[j] << '\n';
					return 0;
				}
			}
	// 팰린드롬이 없는 경우
	cout << 0 << '\n';
	return 0;
}

int main(void)
{
	int t; scanf("%d", &t);
	while(t--)
	{
		int n; scanf("%d", &n);
		vector<string> arr(n);
		for(int i=0; i<n; i++)
			cin >> arr[i];
		bruteforce(arr);
	}
}

/*
	
*/