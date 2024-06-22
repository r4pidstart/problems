// https://www.acmicpc.net/problem/2248
// 2024-06-21 01:12:55
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

long ncr(int n, int r)
{
    static vector<vector<long> > dp(32, vector<long>(32, -1));
    if(r==0 or n==0 or r==n) return 1;

    if(dp[n][r]!=-1)
        return dp[n][r];

    return dp[n][r]=ncr(n-1, r)+ncr(n-1, r-1);
}

long count_number(long mid, long l)
{
    // mid보다 같거나 작으면서 l개 이하의 비트를 사용한 숫자의 개수
    bitset<32> bi(mid);
    
    long ret=0, cnt=0;
    for(int i=31; i>=0; i--)
    {
        if(bi[i])
        {
            for(int j=0; j<=l-cnt; j++)
                if(i>=j)
                    ret+=ncr(i, j);
            cnt++;
        }
    }
#ifdef LOCAL
    cout << mid << ' ' << ret << '\n';
#endif
    if(bi.count()<=l)
        ret++;
    return ret;
}

long solution(long n, long l, long i)
{
    long lo=0, hi=UINT32_MAX, ans=0;
    while(lo<=hi)
    { 
        long mid=(lo+hi)/2;
        if(count_number(mid, l)>=i)
            hi=mid-1, ans=mid;
        else
            lo=mid+1;
    }
#ifdef LOCAL
    cout << ans << '\n';
#endif
    return ans;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    long n,l,i; cin >> n >> l >> i;
    bitset<32> ans=solution(n, l, i);
    for(int i=n-1; i>=0; i--)
        cout << ans[i];
}

/*
    0  
*/