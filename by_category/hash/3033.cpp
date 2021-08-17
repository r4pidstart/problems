// https://www.acmicpc.net/problem/3033
// 2021-08-18 00:55:49 644ms
#include<bits/stdc++.h>
using namespace std;

int n;
string s;
const int MOD1=1'000'000'007, MOD2=1'000'000'009;

int decision(int len)
{
	// get hash of s[0]~s[len-1]
	long long hash1=s[0], hash2=s[0], key1=31, key2=33, del_key1=1, del_key2=1;
	for(int i=1; i<len; i++)
	{
		hash1=(hash1*key1+s[i])%MOD1;
		hash2=(hash2*key2+s[i])%MOD2;
		del_key1=del_key1*key1%MOD1, del_key2=del_key2*key2%MOD2;
	}
	
	unordered_set<long long> se;
	se.reserve(n);
	se.insert(hash1*MOD2 + hash2);

	// rabin-karp
	for(int i=len; i<n; i++)
	{
		hash1=(hash1 - s[i-len]*del_key1%MOD1 + MOD1)%MOD1;
		hash2=(hash2 - s[i-len]*del_key2%MOD2 + MOD2)%MOD2;

		hash1=(hash1*key1+s[i])%MOD1;
		hash2=(hash2*key2+s[i])%MOD2;

		long long target=hash1*MOD2 + hash2;
		if(se.find(target)!=se.end())
			return 1;
		se.insert(target);
	}
	return 0;
}

int optimize()
{
	int lo=1, hi=n, ans=0;
	while(lo<=hi)
	{
		int mid=(lo+hi)/2;
		if(decision(mid))
		{
			lo=mid+1;
			ans=mid;
		}
		else
			hi=mid-1;
	}
	return ans;
}

int main(void)
{
	cin >> n >> s;
	cout << optimize();	
}

/*

*/