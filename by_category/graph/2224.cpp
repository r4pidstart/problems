// https://www.acmicpc.net/problem/2224
// 2022-09-06 23:08:02 4ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > table(128, vector<int>(128, INT32_MAX/2));
    for(int i=0; i<128; i++)
        table[i][i]=0;
    for(int i=0; i<n; i++)
    {
        char a,b; scanf(" %c => %c", &a, &b);
        table[a][b]=0;
    }

    for(int k=0; k<128; k++)
        for(int i=0; i<128; i++)
            for(int j=0; j<128; j++)
                table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
    
    int cnt=0; 
    for(int i=0; i<128; i++)
        for(int j=0; j<128; j++)
            if(i!=j and table[i][j] == 0)
                cnt++;
    printf("%d\n", cnt);
    for(int i=0; i<128; i++)
        for(int j=0; j<128; j++)
            if(i!=j and table[i][j] == 0)
                printf("%c => %c\n", i, j);
}

/*
    
*/