// https://www.acmicpc.net/problem/2473
// 2021-10-13 05:00:41 28ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<long long> arr(n);
    for(int i=0; i<n; i++) scanf("%lld", &arr[i]);
    sort(arr.begin(), arr.end());

    long long ans1=arr[0], ans2=arr[1], ans3=arr[2], dif=INT32_MAX*2LL;
    for(int i=0; i<n-2; i++) // i를 골라두고, 투포인터를 이용함 
    {
        int cur1=i+1, cur2=n-1;
        while(cur1!=cur2)
        {
            if(abs(arr[cur1]+arr[cur2]+arr[i]) < dif)
            {
                dif=abs(abs(arr[cur1]+arr[cur2]+arr[i]));
                ans1=arr[i], ans2=arr[cur1], ans3=arr[cur2];
            }

            if(arr[cur1]+arr[cur2]+arr[i] > 0) cur2--;
            else cur1++;
        }
    }
    printf("%lld %lld %lld", ans1, ans2, ans3);
}

/*
    
*/