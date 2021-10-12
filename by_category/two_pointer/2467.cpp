// https://www.acmicpc.net/problem/2467
// 2021-10-13 04:45:07 24ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);

    int cur1=0, cur2=n-1, ans1=arr[cur1], ans2=arr[cur2], dif=INT32_MAX;
    while(cur1!=cur2)
    {
        if(abs(arr[cur2]+arr[cur1]) < dif)
        {
            dif=abs(arr[cur2]+arr[cur1]);
            ans1=arr[cur1], ans2=arr[cur2];
        }

        if(arr[cur2]+arr[cur1] < 0) cur1++;
        else cur2--;
    }
    printf("%d %d", ans1, ans2);
}

/*
    
*/