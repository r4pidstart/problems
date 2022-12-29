// https://www.acmicpc.net/problem/2285
// 2022-12-30 00:49:19
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n);
    long total=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &arr[i].first, &arr[i].second);
        total+=arr[i].second;
    }
    sort(arr.begin(), arr.end());

    long cnt=0;
    for(int i=0; i<n; i++)
    {
        cnt+=arr[i].second;
        if(total <= cnt*2)
            return !printf("%d", arr[i].first);
    }
}

/*
    
*/