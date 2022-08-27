// https://www.acmicpc.net/problem/3151
// 2022-08-27 23:38:35 1888ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());

    long long ans=0;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            int for_debug=arr[i]+arr[j];
            if(binary_search(arr.begin()+j+1, arr.end(), -(arr[i]+arr[j])))
                ans+=upper_bound(arr.begin()+j+1, arr.end(), -(arr[i]+arr[j])) - lower_bound(arr.begin()+j+1, arr.end(), -(arr[i]+arr[j]));
        }
    printf("%lld", ans);
}

/*
    
*/