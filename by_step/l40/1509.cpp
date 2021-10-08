// https://www.acmicpc.net/problem/1509
// 2021-09-02 00:39:16 108ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    vector<vector<int> > isPalindrome(s.length(), vector<int>(s.length(), 0));
    for(int i=0; i<s.length(); i++)
        isPalindrome[i][i]=1;

    for(int i=0; i<s.length()-1; i++)
        if(s[i]==s[i+1]) isPalindrome[i][i+1]=1;

    for(int d=2; d<s.length(); d++)
    {
        for(int i=0; i+d<s.length(); i++)
            if(isPalindrome[i+1][i+d-1] && s[i]==s[i+d])
                isPalindrome[i][i+d]=1;
    }

    vector<int> dp(s.length()+1,INT32_MAX/2);
    // dp[i] : i번째까지 팰린드롬으로 분할할 수 있는 최솟값
    dp[0]=0;
    for(int i=1; i<=s.length(); i++)
    {
        for(int j=1; j<=i; j++)
            if(isPalindrome[j-1][i-1])
                dp[i]=min(dp[i], dp[j-1]+1);
    }
    printf("%d", dp[s.length()]);
}

/*

*/