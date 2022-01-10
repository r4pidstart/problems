// https://www.acmicpc.net/problem/10709
// 2022-01-11 05:06:54 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int h,w; scanf("%d%d", &h,&w);
    vector<vector<char> > sky(h, vector<char>(w));
    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            scanf(" %c", &sky[i][j]);
    
    vector<vector<int> > dp(h, vector<int>(w+1, -1));
    for(int i=0; i<h; i++)
    {
        for(int j=1; j<=w; j++)
            if(sky[i][j-1]=='c') printf("%d ", dp[i][j]=0);
            else if(dp[i][j-1]!=-1) printf("%d ", dp[i][j]=dp[i][j-1]+1);
            else printf("-1 ");
        printf("\n");
    }
        
}

/*
    
*/