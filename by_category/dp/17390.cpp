// https://www.acmicpc.net/problem/17390
// 2022-07-30 03:51:48 232ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int a,q; scanf("%d%d", &a, &q);
    vector<int> arr(a);
    for(int i=0; i<a; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    
    vector<long long> p_sum(a+1);
    for(int i=1; i<=a; i++)
        p_sum[i]=p_sum[i-1]+arr[i-1];

    while(q--)
    {
        int a,b; scanf("%d%d", &a, &b);
        printf("%lld\n", p_sum[b]-p_sum[a-1]);
    }
}

/*
    
*/