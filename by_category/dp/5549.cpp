// https://www.acmicpc.net/problem/5549
// 2024-01-12 05:33:59
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    int q; scanf("%d", &q);
    vector<vector<char> > table(n, vector<char>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" %c", &table[i][j]);
    
    vector<vector<vector<int> > > psum(3, vector<vector<int> >(n+1, vector<int>(m+1)));
    
    vector<char> target{'J', 'O', 'I'};
    for(int k=0; k<3; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                psum[k][i+1][j+1]=psum[k][i][j+1]+psum[k][i+1][j]-psum[k][i][j]+(table[i][j]==target[k]);

    while(q--)
    {
        int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d);
        for(int i=0; i<3; i++)
            printf("%d ", psum[i][c][d]-psum[i][a-1][d]-psum[i][c][b-1]+psum[i][a-1][b-1]);
        printf("\n");
    }
}   

/*
    
*/