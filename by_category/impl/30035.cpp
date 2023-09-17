// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int mov(int& x, int& y, char c, vector<vector<char> >& table)
{
    int dx,dy;
    switch (c)
    {
    case 'U':
        dx=-1, dy=0;
        break;
    case 'D':
        dx=1, dy=0;
        break;
    case 'L':
        dx=0, dy=-1;
        break;
    case 'R':
        dx=0, dy=1;
        break;
    }    

    int n=table.size();
    int nx=x+dx, ny=y+dy;
    if(0<=nx and nx<n and 0<=ny and ny<n)
    {
        if(table[nx][ny] == '.')
        {
            table[x][y]='.';
            table[nx][ny]='@';
            x=nx, y=ny;
        }
    }
    return 0;
}

int jump(int x, int y, int& ink_amount, char ink, vector<vector<char> >& table)
{
    int n=table.size();
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(abs(x-i)+abs(y-j) <= ink_amount)
                if(table[i][j] != '@' and table[i][j] != '.')
                    table[i][j]=ink;
        }
    ink_amount=0;
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int i,n,k; scanf("%d%d%d", &i, &n, &k);
    string ink_string;
    cin >> ink_string;
    
    int x,y;
    vector<vector<char> > table(n, vector<char>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            scanf(" %c", &table[i][j]);
            if(table[i][j] == '@')
                x=i, y=j;
        }
    
    string s; 
    cin >> s;

    int ink_idx=0, ink_amount=0;
    for(char c : s)
    {
        if(c=='U' or c=='D' or c=='L' or c=='R')
            mov(x, y, c, table);
        else if(c=='j')
            ink_amount++;
        else if(c=='J')
        {
            jump(x, y, ink_amount, ink_string[ink_idx], table);
            ink_idx=(ink_idx+1)%ink_string.size();   
        }
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%c", table[i][j]);
        printf("\n");
    }
}

/*
    
*/