// https://www.acmicpc.net/problem/2559
// 2022-04-08 01:24:52 12ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n,&k);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    int sum=accumulate(arr.begin(), arr.begin()+k, 0);
    int maxsum=sum;
    for(int i=k; i<n; i++)
    {
        sum=sum-arr[i-k]+arr[i];
        maxsum=max(maxsum, sum);
    }
    printf("%d", maxsum);
}

/*
    
*/