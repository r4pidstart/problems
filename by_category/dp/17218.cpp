// https://www.acmicpc.net/problem/17218
// 2023-08-20 00:11:36
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s1, s2;
    cin >> s1 >> s2;
    
    vector<vector<int> > dp(s1.length()+1, vector<int>(s2.length()+1));
    vector<vector<pair<int,int> > > prev(s1.length()+1, vector<pair<int,int> >(s2.length()+1));

    for(int i=1; i<=s1.length(); i++)
        for(int j=1; j<=s2.length(); j++)
        {
            if(s1[i-1]==s2[j-1]) 
            {
                dp[i][j]=dp[i-1][j-1]+1;
                prev[i][j]={i-1, j-1};
            }
            else
            {
                if(dp[i-1][j] > dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    prev[i][j]=prev[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                    prev[i][j]=prev[i][j-1];
                }
            }
        }
    pair<int,int> cur=prev[s1.length()][s2.length()];
    vector<char> ans;
    while(cur.first or cur.second)
    {
        ans.push_back(s1[cur.first]);
        cur=prev[cur.first][cur.second];
    }
    for(auto it=ans.rbegin(); it!=ans.rend(); it++)
        printf("%c", *it);
    // printf("%d", dp[s1.length()][s2.length()]);
}

/*
    
*/