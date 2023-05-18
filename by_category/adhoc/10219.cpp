// https://www.acmicpc.net/problem/10219
// 2023-05-19 00:07:04                  
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int h,w; scanf("%d%d", &h, &w);
        vector<vector<char> > table(h, vector<char>(w));
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
                scanf(" %c", &table[i][j]);
        
        for(int i=0; i<h; i++)
        {
            for(int j=w-1; j>=0; j--)
                printf("%c", table[i][j]);
            printf("\n");
        }
    }
}

/*
    
*/