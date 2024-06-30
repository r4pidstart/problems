// https://www.acmicpc.net/problem/1229
// 2024-06-28 09:18:09
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int solution(int now, int n, const vector<int>& six, int init=0)
{
    static vector<int> dp(six.back()+1, -1);
    if(init)   
    {
        for(int i=0; i<six.size(); i++)
            for(int j=0; j<six.size(); j++)
                if(n-six[i]-six[j] >= 0)
                    dp[n-six[i]-six[j]]=2;

        for(int i=0; i<six.size(); i++)
            if(n-six[i] >= 0)
                dp[n-six[i]]=1;
    }
    
    if(now==n)
        return 0;
    if(dp[now]!=-1)
        return dp[now];

    int ret=6;
    for(int i=six.size()-1; i>=0; i--)
    {
        if(ret==3)
            break;
            
        if(now+six[i] <= n)
            ret=min(ret, solution(now+six[i], n, six)+1);
    }

    return dp[now]=ret;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    vector<int> six(1, 1);
    while(six.back() < n)
        six.push_back(six.size()*6 - (six.size()*2-1) + six.back());

    cout << solution(0, n, six, 1);
}

/*
    
*/