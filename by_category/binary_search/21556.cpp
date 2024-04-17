// https://www.acmicpc.net/problem/21556
// 2024-04-17 00:20:53
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<long> arr(n);
    for(int i=0; i<n; i++)
        scanf("%ld", &arr[i]);
    sort(arr.begin(), arr.end());

    long lo=0, hi=2e9, ans=2e9;
// #ifdef LOCAL
//     lo=0, hi=10000, ans=10000;
// #endif

    long target=1L*n*(n-1)/2;
    while(lo<=hi)
    {
        long mid=(lo+hi)/2;
        
        long cnt=0; // arr[i]+x<=mid인 쌍의 개수
        for(int i=0; i<n; i++)
        {
            auto it=upper_bound(arr.begin(), arr.end(), mid-arr[i]);
            cnt+=n-(arr.end()-it);
            if(arr[i] <= mid-arr[i]) cnt--;
        }
        if(cnt<target)
            lo=mid+1, ans=mid;
        else
            hi=mid-1;
    }

    // ans보다 크면서 가장 작은 쌍 고르기
    lo=0, hi=n-1;
    long answer=LONG_MAX/2;
    while(lo<hi)
    {
        if(arr[lo]+arr[hi] <= ans)
            lo++;
        else
            answer=min(answer, arr[lo]+arr[hi]), hi--;
    }

#ifdef LOCAL
    vector<long> tmp;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            tmp.push_back(arr[i]+arr[j]);
    sort(tmp.begin(), tmp.end());
    
    printf("---\n");
    for(long i : tmp)
        printf("%ld ", i);
    printf("\n--- your: %ld, actual: %ld\n", answer, tmp[ceil(1.*target/2)-1]);
    assert(answer==tmp[ceil(1.*target/2)-1]);
#endif

    printf("%ld", answer);
}

/*
    
*/