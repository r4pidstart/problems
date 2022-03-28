// https://www.acmicpc.net/problem/1051
// 2022-03-29 01:15:36 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > table(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d", &table[i][j]);

    int ans=0;
    for(int s=0; s<min(n,m); s++)
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(i+s < n and j+s < m)
                    if(table[i][j] == table[i+s][j] and table[i+s][j] == table[i+s][j+s] and table[i+s][j+s] == table[i][j+s])
                        ans=max(ans, s+1);
            }
    printf("%d",ans*ans);
}

/*
    
*/