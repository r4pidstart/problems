// https://www.acmicpc.net/problem/30678
// 2024-01-24 22:53:02
#include"bits/stdc++.h"
using namespace std;

const int star[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0},
    {0, 1, 0, 1, 0},
};

int set_star(int x, int y, int n, vector<vector<char> >& table)
{
    if(n==1)
    {
        table[x][y]='*';
        return 0;
    }

    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if(star[i][j])
                set_star(x+i*n/5, y+j*n/5, n/5, table);
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<vector<char> > table(pow(5, n)+1, vector<char>(pow(5, n)+1, ' '));
    set_star(0, 0, pow(5, n), table);

    for(int i=0; i<pow(5, n); i++)
    {
        for(int j=0; j<pow(5, n); j++)
            printf("%c", table[i][j]);
        printf("\n");
    }
}

/*
    
*/