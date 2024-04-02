// https://www.acmicpc.net/problem/14846
// 2024-04-01 22:27:05
#include"bits/stdc++.h"
using namespace std;

int get_area(int x1, int y1, int x2, int y2, int k, const vector<vector<vector<int> > >& table)
{
    assert(x1<=x2 and y1<=y2);
    return table[x2][y2][k]-table[x1-1][y2][k]-table[x2][y1-1][k]+table[x1-1][y1-1][k];
}

int main(void)
{
    int n; scanf("%d", &n);
    vector table(n, vector(n, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &table[i][j]);
    
    vector psum(n+1, vector(n+1, vector(11, 0)));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<11; k++)
                    psum[i][j][k]=psum[i-1][j][k]+psum[i][j-1][k]-psum[i-1][j-1][k]+(table[i-1][j-1]==k);
    
    int q; scanf("%d", &q);
    while(q--)
    {
        int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d);
        int cnt=0;
        for(int i=1; i<11; i++)
            cnt+=!!get_area(a, b, c, d, i, psum);
        printf("%d\n", cnt);
    }
}

/*
    d
*/