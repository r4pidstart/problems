// https://www.acmicpc.net/problem/20205
// 2022-07-02 23:12:59 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    vector<vector<int> > table(n, vector<int>(n));

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &table[i][j]);

    for(int i=0; i<n; i++)
    {
        for(int a=0; a<k; a++)
        {
            for(int j=0; j<n; j++)
                for(int b=0; b<k; b++)
                    printf("%d ", table[i][j]);
            printf("\n");
        }
    }
}

/*
    
*/