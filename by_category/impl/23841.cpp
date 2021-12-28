// https://www.acmicpc.net/problem/23841
// 2021-12-29 05:55:52 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<vector<char> > arr(n, vector<char>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" %c", &arr[i][j]);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m/2; j++)
        {
            if(arr[i][m-j-1] != arr[i][j])
            {
                if(arr[i][j] != '.') arr[i][m-j-1]=arr[i][j];
                else arr[i][j]=arr[i][m-j-1];
            }
        }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            printf("%c", arr[i][j]);
        printf("\n");
    }

}

/*
    5 -> 0
    4 -> 1
    3 -> 2


*/