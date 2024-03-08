// https://www.acmicpc.net/problem/2159
// 2024-03-03 00:15:05
#include"bits/stdc++.h"
using namespace std;

long dp(int i, int w, const vector<pair<int,int> >& arr)
{
    const int way[5][2]={{0, 0}, {0,1}, {1,0}, {0,-1}, {-1,0}};
    static vector<vector<long> > memo(arr.size()+1, vector<long>(5, -1));
    if(i==arr.size()-1)
        return 0;
    if(memo[i][w] != -1)
        return memo[i][w];

    long ret=LONG_MAX;
    int x=arr[i].first+way[w][0], y=arr[i].second+way[w][1];

    for(int j=0; j<5; j++)
    {
        int nx=arr[i+1].first+way[j][0], ny=arr[i+1].second+way[j][1];
        ret=min(ret, dp(i+1, j, arr)+abs(x-nx)+abs(y-ny));
    }
    
    return memo[i][w]=ret;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n+1);
    for(int i=0; i<=n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    printf("%ld", dp(0, 0, arr));
}

/*
    
*/