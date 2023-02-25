// https://www.acmicpc.net/problem/1911
// 2023-02-26 03:50:20
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,l; scanf("%d%d", &n, &l);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    sort(arr.begin(), arr.end());

    int cnt=0, prev=0;
    for(int i=0; i<n; i++)
    {
        arr[i].first=max(prev, arr[i].first);
        if(arr[i].second <= arr[i].first) continue;

        int tmp=(arr[i].second-arr[i].first+l-1)/l;
        prev=arr[i].first+tmp*l;
        cnt+=tmp;
    }
    printf("%d", cnt);
}

/*
    
*/