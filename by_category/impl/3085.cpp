// https://www.acmicpc.net/problem/3085 
// 2022-03-23 23:14:37 76ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int ans=0, n; scanf("%d", &n);
    vector<vector<int> > table(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf(" %c", &table[i][j]);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            // swap1
            if(i+1 != n)
            {
                swap(table[i][j], table[i+1][j]);
                
                // check
                for(int k=0; k<n; k++)
                {
                    int tmp=0;
                    for(int l=0; l<n; l++)
                    {
                        if(l and table[k][l] != table[k][l-1]) tmp=1;
                        else tmp++;
                        ans=max(ans, tmp);
                    }
                }
                
                for(int k=0; k<n; k++)
                {
                    int tmp=0;
                    for(int l=0; l<n; l++)
                    {
                        if(l and table[l][k] != table[l-1][k]) tmp=1;
                        else tmp++;
                        ans=max(ans, tmp);
                    }
                }
                swap(table[i][j], table[i+1][j]);
            }

            if(j+1 != n)
            {
                // swap2
                swap(table[i][j], table[i][j+1]);

                // check
                for(int k=0; k<n; k++)
                {
                    int tmp=0;
                    for(int l=0; l<n; l++)
                    {
                        if(l and table[k][l] != table[k][l-1]) tmp=1;
                        else tmp++;
                        ans=max(ans, tmp);
                    }
                }
                
                for(int k=0; k<n; k++)
                {
                    int tmp=0;
                    for(int l=0; l<n; l++)
                    {
                        if(l and table[l][k] != table[l-1][k]) tmp=1;
                        else tmp++;
                        ans=max(ans, tmp);
                    }
                }
                swap(table[i][j], table[i][j+1]);
            }
        }
    
    printf("%d", ans);
}

/*
    
*/