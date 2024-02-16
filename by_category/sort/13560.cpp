// https://www.acmicpc.net/problem/13560
// 2024-02-13 03:44:48
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
        
    sort(arr.begin(), arr.end());
    if(accumulate(arr.begin(), arr.end(), 0) != n*(n-1)/2)
        return !printf("-1");

    int cnt=0;
    for(int i=0; i<n; i++)
    {
        cnt+=arr[i]-i;
        if(cnt<0)
            return !printf("-1");
    }
    if(cnt)
        return !printf("-1");
    printf("1");
}

/*
    
*/