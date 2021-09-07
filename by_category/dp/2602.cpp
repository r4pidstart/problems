// https://www.acmicpc.net/problem/2602
// 2021-09-08 01:54:01 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string target, s[2];
    cin >> target >> s[0] >> s[1];
    vector<vector<vector<int> > > dp(s[0].length()+1, vector<vector<int> >(2, vector<int>(target.length()+1, 0)));
    // dp[i][j][k] : i번 문자를 j번 문자열에서, k번째 문자까지 진행하는 방법의 수 
    for(int i=1; i<=s[0].length(); i++)
        for(int j=0; j<2; j++)
            if(target[0]==s[j][i-1])
                dp[i][j][1]=1;

    for(int i=1; i<=s[0].length(); i++)
        for(int j=0; j<2; j++)
        {
            for(int k=1; k<target.length(); k++)
                if(dp[i][j][k])
                    for(int it=i; it<s[0].length(); it++)
                        if(target[k]==s[(j+1)%2][it])
                            dp[it+1][(j+1)%2][k+1]+=dp[i][j][k];
            
            dp[i][j][target.length()]+=dp[i-1][j][target.length()];
        }
    printf("%d", dp[s[0].length()][0][target.length()]+dp[s[0].length()][1][target.length()]);
}

/*

*/