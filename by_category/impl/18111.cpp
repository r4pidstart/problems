// https://www.acmicpc.net/problem/18111
// 2022-03-31 23:14:05 152ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m,b; scanf("%d%d%d", &n, &m, &b);
    vector<vector<int> > table(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &table[i][j]);
        
    int ansT=INT32_MAX, ansH=0;
    for(int h=256; h>=0; h--)
    {
        int used_block=0, used_time=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(table[i][j] < h)
                    used_block+=h-table[i][j], used_time+=h-table[i][j];
                else if(table[i][j] > h)
                    used_block-=table[i][j]-h, used_time+=2*(table[i][j]-h);
            }
        
        if(used_block <= b and used_time < ansT)
            ansT=used_time, ansH=h; 
    }
    printf("%d %d", ansT, ansH);
}

/*
    
*/