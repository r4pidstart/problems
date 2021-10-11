// https://www.acmicpc.net/problem/20551
// 2021-10-12 00:59:05 180ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, m; scanf("%d%d", &n, &m);
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    sort(arr.begin(), arr.end());

    for(int i=0; i<m; i++)
    {
        int target; scanf("%d", &target);
        auto it=binary_search(arr.begin(), arr.end(), target);
        printf("%ld\n", it!=0 ? lower_bound(arr.begin(), arr.end(), target)-arr.begin():-1);
    }
}

/*
    
*/