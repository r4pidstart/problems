// https://www.acmicpc.net/problem/9252
// 2021-04-29 00:24:03 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int> > dp(s1.length()+1, vector<int> (s2.length()+1, 0));
    int size1=s1.length(), size2=s2.length();
    for(int i=1; i<=size1; i++)
    {
        for(int j=1; j<=size2; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    printf("%d\n", dp[size1][size2]);
    int x=size1, y=size2;
    vector<char> ans;
    while(!dp[x][y]==0)
    {
        if(dp[x][y]==dp[x-1][y] && x-1!=0)
            x--;
        else if(dp[x][y]==dp[x][y-1] && y-1!=0)
            y--;
        else
        {
            ans.push_back(s1[x-1]);
            x--, y--;
        }
    }
    reverse(ans.begin(), ans.end());
    for(char c : ans)
        printf("%c", c);
}