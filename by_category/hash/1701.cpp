// https://www.acmicpc.net/problem/1701
// 2021-08-14 04:12:24 16ms
//#include<bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int length;
string s;
vector<long long> hashed1, hashed2, pow_dp1, pow_dp2;
const int MOD1 = 1'000'000'007;
const int MOD2 = 1'000'000'009;

int decision(int len)
{
	// check whether there exists repeated subsequence
	unordered_set<int> st1, st2;
	long long hash1, hash2;
	int l = 0, r = len;
	while (r <= length)
	{
		hash1 = ((hashed1[r] - hashed1[l] + MOD1) % MOD1) * pow_dp1[length - r] % MOD1;
		hash2 = ((hashed2[r] - hashed2[l] + MOD2) % MOD2) * pow_dp2[length - r] % MOD2;
		if ((st1.find(hash1) != st1.end()) && (st2.find(hash2) != st2.end()))
			return 1;
		st1.insert(hash1);
		st2.insert(hash2);
		l++, r++;
	}
	return 0;
}

int optimize(void)
{
	int lo = 1, hi = length, ans = 0;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (decision(mid))
		{
			ans = mid;
			lo = mid + 1;
		}
		else
		{
			hi= mid-1;
		}
	}

	return ans;
}

void hashing(void)
{
	hashed1.assign(length + 1, 0);
	hashed2.assign(length + 1, 0);
	pow_dp1.assign(length, 1);
	pow_dp2.assign(length, 1);

	for (int i = 1; i < length; i++)
	{
		pow_dp1[i] = pow_dp1[i - 1] * 31 % MOD1;
		pow_dp2[i] = pow_dp2[i - 1] * 31 % MOD2;
	}

	for (int i = 1; i <= length; i++)
	{
		hashed1[i] = (hashed1[i - 1] + s[i - 1] * pow_dp1[i - 1]) % MOD1;
		hashed2[i] = (hashed2[i - 1] + s[i - 1] * pow_dp2[i - 1]) % MOD2;
	}
}

int main(void)
{
	freopen("input.txt", "r", stdin);
	cin >> s;
	length=s.length();
	hashing();
	cout << optimize();
}

/*

*/