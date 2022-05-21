// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<pair<int,int> > arr(m);
    for(int i=0; i<m; i++)
        scanf("%d %d", &arr[i].first, &arr[i].second);

    sort(arr.begin(), arr.end());

    int cost=0;
    for(int i=0; i<m; i++)
    {
        if(arr[i].second > n)
            cost+=arr[i].first * n, n=0;
        else
            cost+=arr[i].first * arr[i].second, n-=arr[i].second;
    }

    printf("%d", cost);
}

/*
    
*/