// https://www.acmicpc.net/problem/2167
// 2022-03-17 15:10:55 400ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > arr(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
             scanf("%d", &arr[i][j]);

    int q; scanf("%d", &q);
    while(q--)
    {
        int sum=0;
        int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d);
        for(int i=a-1; i<c; i++)
            for(int j=b-1; j<d; j++)
                sum+=arr[i][j];
        printf("%d\n", sum);
    }
}

/*
    
*/