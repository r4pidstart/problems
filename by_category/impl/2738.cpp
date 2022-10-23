// https://www.acmicpc.net/problem/2738
// 2022-10-24 00:29:39
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > arr(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &arr[i][j]);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int a; scanf("%d", &a);
            printf("%d ", a+arr[i][j]);           
        }
        printf("\n");
    }
}

/*
    
*/
