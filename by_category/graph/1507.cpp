// https://www.acmicpc.net/problem/1507
// 2023-11-02 20:55:10
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<vector<int> > table(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &table[i][j]);

    vector<vector<int> > copied=table;
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                copied[i][j]=min(copied[i][j], copied[i][k]+copied[k][j]);
    
    if(copied != table)
        return !printf("-1");

    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(table[i][k] and table[k][j] and table[i][k]+table[k][j]==table[i][j])
                    table[i][j]=INT32_MAX/2;
    
#ifdef LOCAL
    printf("\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%d ", table[i][j]==INT32_MAX/2 ? 0 : table[i][j]);
        printf("\n");
    }
#endif

    int ans=0;
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            if(table[i][j] != INT32_MAX/2)
                ans+=table[i][j];
    printf("%d", ans);
}

/*
    
*/