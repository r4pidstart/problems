// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > arr, psum;

inline int getsum(int x, int y, int a, int b)
{
    return psum[a][b]+psum[x-1][y-1]-psum[a][y-1]-psum[x-1][b];
}

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    arr.assign(n, vector<int>(m)), psum.assign(n+1, vector<int>(m+1));
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) 
            scanf("%d", &arr[i][j]);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+arr[i-1][j-1];

    int ans=INT32_MIN;
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++)
            for(int k=1; k<=m; k++)
                for(int l=k; l<=m; l++)
                    ans=max(ans, getsum(i,k,j,l));
    printf("%d", ans);
}

/*
    
*/