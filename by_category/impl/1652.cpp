// https://www.acmicpc.net/problem/1652
// 2022-04-01 03:58:02 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<char> > table(n+1, vector<char>(n+1, 'X'));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf(" %c", &table[i][j]);

    int cnt1=0, cnt2=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n-1; j++)   
            if(table[i][j-1] == 'X' and table[i][j]=='.' and table[i][j+1]=='.') cnt1++;

    for(int i=1; i<=n-1; i++)
        for(int j=1; j<=n; j++)
            if(table[i-1][j] == 'X' and table[i][j]=='.' and table[i+1][j]=='.') cnt2++;
    
    printf("%d %d", cnt1, cnt2);
}

/*
    
*/