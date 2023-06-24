// https://www.acmicpc.net/problem/14391
// 2023-06-24 19:38:50
#include"bits/stdc++.h"
using namespace std;

int bf(int x, int y, int sum, vector<vector<int> >& table)
{
    static vector<vector<int> > used(table.size(), vector<int>(table[0].size()));

    if(x==table.size())
        return sum;
    if(y==table[0].size())
        return bf(x+1, 0, sum, table);
    if(used[x][y])
        return bf(x, y+1, sum, table);

    int ret=0;
    // to left
    {
        int tmp=0, i;
        for(i=0; i<table[0].size()-y; i++)
        {
            tmp=tmp*10+table[x][y+i];
            if(used[x][y+i]) break;
            used[x][y+i]=1;
            ret=max(ret, bf(x, y+i+1, sum+tmp, table));
        }

        while(i--)
            used[x][y+i]=0;
    }

    // to down
    {
        int tmp=0, i;
        for(i=0; i<table.size()-x; i++)
        {
            tmp=tmp*10+table[x+i][y];
            if(used[x+i][y]) break;
            used[x+i][y]=1;
            ret=max(ret, bf(x, y+1, sum+tmp, table));
        }
        
        while(i--)
            used[x+i][y]=0;
    }
    return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > table(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d", &table[i][j]);
    
    printf("%d", bf(0, 0, 0, table));
}

/*
    
*/