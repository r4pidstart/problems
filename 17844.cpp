// https://www.acmicpc.net/problem/17844
// 2021-08-30 03:05:45 516ms
#include<bits/stdc++.h>
using namespace std;

string s;
const int MOD1=1e9+7, MOD2=1e9+9;

int decision(int n)
{
    unordered_map<long long, int> udm;
    udm.reserve(200000);
    // udm[hash]=loca

    long long hash1=s[0], hash2=s[0], mul1=1, mul2=1;

    if(s.length() < n) return 0;
    for(int i=1; i<n; i++)
    {
        hash1=(hash1*31 + s[i])%MOD1;
        hash2=(hash2*31 + s[i])%MOD2;
        mul1=(mul1*31)%MOD1, mul2=(mul2*31)%MOD2;
    }
    udm.insert({hash1*MOD1 + hash2, n-1});

    for(int i=n; i<s.length(); i++)
    {
        hash1=(hash1 - s[i-n]*mul1%MOD1 + MOD1)%MOD1;
        hash2=(hash2 - s[i-n]*mul2%MOD2 + MOD2)%MOD2;

        hash1=(hash1*31 + s[i])%MOD1;
        hash2=(hash2*31 + s[i])%MOD2;

        long long target=hash1*MOD1 + hash2;
        auto it=udm.find(target);
        if(it != udm.end())
        {
            if(it->second < i-n+1) return 1;
            // (0 1 2) (3 4 5)
        }
        else
        {
            udm.insert({target, i});
        }
    }
    return 0;
}

int optimize()
{
    int lo=0, hi=200000, ans;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(decision(mid))
        {
            ans=mid;
            lo=mid+1;
        }
        else
            hi=mid-1;
    }
    if(ans==0) ans=-1;
    return ans;
}

int main(void)
{
    cin >> s;
    printf("%d", optimize());
}

/*
      
*/