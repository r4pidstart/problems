// https://www.acmicpc.net/problem/1415
// 2023-08-01 00:57:17
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    arr.push_back(INT32_MAX);

    int sum=accumulate(arr.begin(), arr.end()-1, 0);
    deque<pair<int, int> > cnt;
    int prev=arr[0], tmpcnt=1;
    for(int i=1; i<=n; i++)
        if(prev!=arr[i]) cnt.push_back({arr[i-1], tmpcnt}), tmpcnt=1, prev=arr[i];
        else tmpcnt++;

    vector<int> prime_table(sum+1, 1);
    prime_table[0]=prime_table[1]=0;
    for(int i=2; i*i<sum+1; i++)
    {
        if(prime_table[i])
            for(int j=i*2; j<sum+1; j+=i)
                prime_table[j]=0;
    }
    vector<int> primes;
    for(int i=2; i<sum+1; i++)
        if(prime_table[i]) primes.push_back(i);

    vector<vector<long> > memo(2, vector<long>(sum+1));
    memo[0][0]=memo[1][0]=1+(arr[0]==0 ? cnt[0].second:0);

    for(int i=0; i<cnt.size(); i++)
    {
        memo[i&1]=vector<long>(sum+1);
        memo[i&1][0]=1+(arr[0]==0 ? cnt[0].second:0);
        for(int use=0; use<=cnt[i].second; use++)
            for(int j=1; j<=sum; j++)
                if(j-cnt[i].first*use>=0)
                    memo[i&1][j]+=memo[!(i&1)][j-cnt[i].first*use];
    }

    long ans=0;
    for(int p : primes)
        ans+=memo[!(cnt.size()&1)][p];
    printf("%ld", ans);
}

/*
    
*/