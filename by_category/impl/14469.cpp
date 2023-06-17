// https://www.acmicpc.net/problem/14469
// 2023-06-17 23:48:55
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    sort(arr.begin(), arr.end());

    int prev=0;
    for(int i=0; i<n; i++)
    {
        if(prev<arr[i].first)
            prev=arr[i].first+arr[i].second;
        else
            prev+=arr[i].second;
    }
    printf("%d", prev);
}

/*
    
*/