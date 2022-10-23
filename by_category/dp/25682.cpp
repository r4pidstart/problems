// https://www.acmicpc.net/problem/25682
// 2022-10-24 00:39:55
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m,k; scanf("%d%d%d", &n, &m, &k);
    vector<vector<char> > table(n, vector<char>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" %c", &table[i][j]);
    
    vector<vector<int> > t1(n+1, vector<int>(m+1)),t2(n+1, vector<int>(m+1));
    
    int ans=INT32_MAX;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(i&1)
            {
                if(j&1)
                {
                    t1[i+1][j+1]=t1[i][j+1]+t1[i+1][j]-t1[i][j]+(table[i][j]=='B');
                    t2[i+1][j+1]=t2[i][j+1]+t2[i+1][j]-t2[i][j]+(table[i][j]=='W');
                }
                else
                {
                    t1[i+1][j+1]=t1[i][j+1]+t1[i+1][j]-t1[i][j]+(table[i][j]=='W');
                    t2[i+1][j+1]=t2[i][j+1]+t2[i+1][j]-t2[i][j]+(table[i][j]=='B');
                }
            }
            else
            {
                if(j&1)
                {
                    t1[i+1][j+1]=t1[i][j+1]+t1[i+1][j]-t1[i][j]+(table[i][j]=='W');
                    t2[i+1][j+1]=t2[i][j+1]+t2[i+1][j]-t2[i][j]+(table[i][j]=='B');
                }
                else
                {
                    t1[i+1][j+1]=t1[i][j+1]+t1[i+1][j]-t1[i][j]+(table[i][j]=='B');
                    t2[i+1][j+1]=t2[i][j+1]+t2[i+1][j]-t2[i][j]+(table[i][j]=='W');
                }
            }

            if(i+1>=k and j+1>=k)
                ans=min({ans, 
                    t1[i+1][j+1]-t1[i+1-k][j+1]-t1[i+1][j+1-k]+t1[i+1-k][j+1-k],
                    t2[i+1][j+1]-t2[i+1-k][j+1]-t2[i+1][j+1-k]+t2[i+1-k][j+1-k]});
        }

    printf("%d", ans);
}

/*
    
*/