// https://www.acmicpc.net/problem/2448
// 2024-01-24 02:21:21
#include"bits/stdc++.h"
using namespace std;

int draw(int x, int y, int h, vector<vector<char> >& table)
{
    if(h==1) return 0;
    // fill this triangle
    for(int i=0; i<h; i++)
        for(int j=h-i-1; j<2*h-(h-i); j++)
            table[x+i][y+j]='*';

    draw(x, y+h/2, h/2, table);
    draw(x+h/2, y, h/2, table);
    draw(x+h/2, y+h, h/2, table);

    for(int i=0; i<h/2; i++)
        for(int j=h==3; j<h-1-2*i; j++)
            table[x+i+h/2][y+h/2+j+i]=' ';

    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<vector<char> > table(n, vector<char>(n*2-1, ' '));
    draw(0, 0, n, table);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2*n-1; j++)
            printf("%c", table[i][j]);
        printf("\n");
    }
}

/*
    
*/