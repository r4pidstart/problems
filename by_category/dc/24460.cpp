// https://www.acmicpc.net/problem/24460
// 2022-11-20 02:34:22
#include"bits/stdc++.h"
using namespace std;

int dc(int x, int y, int n, vector<vector<int> >& table)
{
    if(n==1) return table[x][y];
    
    vector<int> arr;
    arr.push_back(dc(x, y, n/2, table));
    arr.push_back(dc(x+n/2, y, n/2, table));
    arr.push_back(dc(x, y+n/2, n/2, table));
    arr.push_back(dc(x+n/2, y+n/2, n/2, table));
    sort(arr.begin(), arr.end());
    return arr[1];
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > table(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &table[i][j]);
    
    printf("%d", dc(0, 0, n, table));
}

/*
    
*/  