// https://www.acmicpc.net/problem/1256
// 2021-08-31 06:12:33 0ms
#include<bits/stdc++.h>
using namespace std;

int n,m,k,flag=0;
string ans;
vector<vector<int> > memo(101,vector<int>(101,0));
// memo[n][m]=a n개 z m개로 만들 수 있는 문자열 갯수

void dp(int a, int b, int now)
{
    if(a==0)
    {
        while(b--) ans+='z';
    }
    else if(b==0)
    {
        while(a--) ans+='a';
    }
    else if(memo[a][b] >= now)
    {
        if(memo[a-1][b] >= now)
        {
            ans+='a';
            dp(a-1, b, now);
        }
        else
        {
            ans+='z';
            dp(a, b-1, now-memo[a-1][b]);
        }
    }   
    else
        flag++;
}

int main(void)
{
    scanf("%d%d%d", &n,&m,&k);

    for(int i=0; i<=n; i++)
        memo[i][0]=1;
    for(int i=0; i<=m; i++)
        memo[0][i]=1;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(memo[i][j-1] > (int)1e9 || memo[i-1][j] > (int)1e9) memo[i][j]=(int)1e9+1;
            else memo[i][j]=memo[i][j-1]+memo[i-1][j];
        }

    dp(n,m,k);
    if(flag)
    {
        printf("-1");
        return 0;
    }
    cout << ans;
}

/*
    2 2
    aazz
    azaz
    azza
    zaaz
    zaza
    zzaa
*/