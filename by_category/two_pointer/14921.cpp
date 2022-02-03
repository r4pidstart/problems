// https://www.acmicpc.net/problem/14921
// 2022-02-04 01:17:08 20ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    int cur1=0, cur2=n-1, prev=arr[cur2]+arr[cur1];
    while(cur1 < cur2)
    {
        if(abs(prev) > abs(arr[cur2]+arr[cur1]))
            prev=arr[cur2]+arr[cur1];
        if(arr[cur2]+arr[cur1] < 0) cur1++;
        else cur2--;
    }
    printf("%d", prev);
}

/*
    
*/