// https://www.acmicpc.net/problem/2548
// 2022-04-11 14:38:09 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    sort(arr.begin(), arr.end());

    int accumulated=0, total_sum=accumulate(arr.begin(), arr.end(), 0);
    int ans=0, mindif=INT32_MAX;
    for(int i=0; i<n; i++)
    {
        // 앞 놈들과의 차이 -> arr[i]*i - accumulated
        // 뒷 놈들과의 차이 -> total_sum - accumulated - arr[i]*(n-i)
        int nowdif=arr[i]*i - accumulated + total_sum - accumulated - arr[i]*(n-i);
        if(mindif > nowdif)
            ans = arr[i], mindif=nowdif;
        accumulated+=arr[i];
    }
    printf("%d", ans);
}

/*

*/