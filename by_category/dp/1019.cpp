// https://www.acmicpc.net/problem/1019
// 2024-02-15 01:01:03
#include"bits/stdc++.h"
using namespace std;

// digit==2 -> returns 00~99
vector<long> solution(int digit, int leading, vector<long>& dp)
{
    if(digit==0)
        return vector<long>(10);
    if(digit==1)
        return {leading, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    vector<long> ret(10);
    vector<long> nxt=solution(digit-1, leading, dp);

    for(int i=0; i<10; i++)
        ret[i]+=nxt[i]*10;
    
    for(int i=!leading; i<10; i++)
        ret[i]+=dp[digit-1];
    
    return ret;
}

int main(void)
{
    int n; scanf("%d", &n);

    vector<long> dp;
    for(long i=1; i<1e12; i*=10)
        dp.push_back(i);

    vector<long> prev(10);
    for(int i=1; i<=n%10; i++)
        prev[i]++;

    string s=to_string(n);
    for(int i=1; i<s.length(); i++)
    {
        int a=s[s.length()-i-1]-'0';
        vector<long> now(10, 0);

        auto tmp=solution(i, 1, dp);

        for(int i=0; i<10; i++)
            now[i]+=tmp[i]*a;

        for(int j=0; j<a; j++)
            now[j]+=dp[i];
        now[0]-=dp[i];
        
        for(int i=0; i<10; i++)
            now[i]+=prev[i];

        now[a]+=(stoi(to_string(n).substr(s.length()-i))+1);
        prev=now;
    }

    for(int i=0; i<10; i++)
        printf("%ld ", prev[i]);
}

/*

*/