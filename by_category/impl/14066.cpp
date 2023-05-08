// https://www.acmicpc.net/problem/14066
// 2023-05-08 21:19:17
#include"bits/stdc++.h"
using namespace std;

const char cube[6][8]=
{
    {"+---+.."},
    {"|   |/."},
    {"|   | +"},
    {"+---+ |"},
    {"./   /|"},
    {"..+---+"},
};

int min_x=INT32_MAX, max_x=INT32_MIN, min_y=INT32_MAX, max_y=INT32_MIN;
int drop_cube(int x, int y, vector<vector<char> >& table, int cnt)
{
    int pos_x=x*2 + 1, pos_y=y*4+1 + 2*x;
    
    while(cnt--)
    {
        for(int i=0; i<6; i++)
            for(int j=0; j<7; j++)
            {
                if(cube[i][j] != '.')// and table[pos_x+i][pos_y+j] == '.')
                    table[pos_x+i][pos_y+j]=cube[i][j];
                min_x=min(pos_x+i, min_x), min_y=min(pos_y+j, min_y);
                max_x=max(pos_x+i, max_x), max_y=max(pos_y+j, max_y);
            }
        pos_x+=3;
    }
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    vector<vector<char> > table(1000, vector<char>(1000, '.'));
    int n,m; scanf("%d%d", &n, &m);

    for(int i=n-1; i>=0; i--) // 뒤부터
        for(int j=0; j<m; j++) // 왼쪽부터
        {
            int cnt; scanf("%d", &cnt);
            drop_cube(i, j, table, cnt);
        }
        
    for(int i=max_x; i>=min_x; i--)
    {
        for(int j=min_y; j<=max_y; j++)
            printf("%c", table[i][j]);
        printf("\n");
    }
}

/*
    
*/