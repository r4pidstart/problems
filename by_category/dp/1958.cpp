// https://www.acmicpc.net/problem/1958
// 2021-09-01 01:34:32 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    int lcs[s1.length()+1][s2.length()+1][s3.length()+1]={};

    for(int i=1; i<=s1.length(); i++)
        for(int j=1; j<=s2.length(); j++)
            for(int k=1; k<=s3.length(); k++)
            {
                if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])
                    lcs[i][j][k]=lcs[i-1][j-1][k-1]+1;
                else
                    lcs[i][j][k]=max({lcs[i-1][j][k], lcs[i][j-1][k], lcs[i][j][k-1]});
            }
    printf("%d", lcs[s1.length()][s2.length()][s3.length()]);
}

/*

*/