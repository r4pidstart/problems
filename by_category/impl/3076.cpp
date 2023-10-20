// https://www.acmicpc.net/problem/3076
// 2023-10-21 02:50:21
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,a,b; scanf("%d%d%d%d", &n, &m, &a, &b);
    vector<vector<char> > table(n*a, vector<char>(m*b, '.'));

    for(int i=0; i<n*a; i++)
        for(int j=0; j<m*b; j++)
        {
            if((i/a)&1)
            {
                if((j/b)&1) table[i][j]='X';
            }
            else
            {
                if(((j/b)&1) == 0) table[i][j]='X';
            }
        }
    
    for(int i=0; i<n*a; i++)
    {
        for(int j=0; j<m*b; j++)
            printf("%c", table[i][j]);
        printf("\n");
    }
}

/*
    
*/