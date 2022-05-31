// https://www.acmicpc.net/problem/1996
// 2022-06-01 03:59:10 128ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > table(n, vector<int>(n));

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            char c;
            scanf(" %c", &c);
            if(c == '.') table[i][j]=0;
            else table[i][j]=c-'0';
        }
    
    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(table[i][j] != 0) printf("*");
            else
            {
                int cnt=0;
                for(int w=0; w<8; w++)
                {
                    int nx=i+way[w][0], ny=j+way[w][1];
                    if(nx < 0 or n <= nx or ny < 0 or n <= ny) continue;
                    cnt+=table[nx][ny];
                }
                if(cnt > 9) printf("M");
                else printf("%d", cnt);
            }
        }
        printf("\n");
    }
}

/*
    
*/