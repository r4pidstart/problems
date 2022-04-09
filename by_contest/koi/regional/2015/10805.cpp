// https://www.acmicpc.net/problem/10805
// 2022-04-10 04:26:26 212ms
#include<bits/stdc++.h>
using namespace std;

int dp(int n, int m) // min square to make n*m rectangle
{
    static vector<vector<int> > memo(101, vector<int>(101, -1));
    if(n < m) swap(n,m);

    if(memo[n][m] != -1)
        return memo[n][m];
    else if(n == m)
        return memo[n][m] = 1;
    else if(!n or !m)
        return 0;
    
    int ret=n*m;
    for(int i=1; i<n; i++)
    { 
        // dp(n-i, m) + dp(i, m);
        int tmp=0;
        tmp+=dp(n-i, m);
        tmp+=dp(i, m);
        ret=min(tmp, ret);
    }
    for(int i=1; i<m; i++)
    { 
        // dp(n, m-i) + dp(n, i);
        int tmp=0;
        tmp+=dp(n, m-i);
        tmp+=dp(n, i);
        ret=min(tmp, ret);
    }
    return memo[n][m]=ret;
}

int get_ans(int h1, int w1, int h2, int w2)
{
    static vector<vector<vector<vector<int> > > > memo(51, vector<vector<vector<int> > >(51, vector<vector<int> >(51, vector<int>(51, -1))));
    if(memo[h1][w1][h2][w2] != -1)
        return memo[h1][w1][h2][w2];
    else if(h1==h2 and w1==w2)
        return dp(h1, w1);

    int ret=h1*w1 - h2*w2;
    for(int mid=1; mid<h1; mid++)
    {
        if(mid < h2) ret=min(ret, dp(mid, w1 - w2) + get_ans(h1 - mid, w1, h2 - mid, w2));
        else if(mid > h2) ret=min(ret, get_ans(mid, w1, h2, w2) + dp(h1 - mid, w1));
        else ret=min(ret, dp(mid, w1 - w2) + dp(h1 - mid, w1));
    }
    for(int mid=1; mid<w1; mid++)
    {
        if(mid < w2) ret=min(ret, dp(h1 - h2, mid) + get_ans(h1, w1 - mid, h2, w2 - mid));
        else if(mid > w2) ret=min(ret, get_ans(h1, mid, h2, w2) + dp(h1, w1 - mid));
        else ret=min(ret, dp(h1 - h2, mid) + dp(h1, w1 - mid));
    }

    return memo[h1][w1][h2][w2]=ret;
}

int main(void)
{
    int h1,w1,h2,w2; scanf("%d%d%d%d", &h1, &w1, &h2, &w2);
    printf("%d", get_ans(h1, w1, h2, w2));
}

/*
    
*/