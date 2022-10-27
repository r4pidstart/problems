// https://www.acmicpc.net/problem/9024
// 2022-10-28 01:07:38
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,k; scanf("%d%d", &n, &k);
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);

        sort(arr.begin(), arr.end());
        int le=0, ri=n-1, cnt=0, dif=INT32_MAX;
        while(le<ri)
        {
            if(abs(k-arr[le]-arr[ri]) < dif)
            {
                dif=abs(k-arr[le]-arr[ri]);
                cnt=1;
            }
            else if(abs(k-arr[le]-arr[ri]) == dif)
                cnt++;
                
            if(arr[le]+arr[ri] < k) le++;
            else ri--;
        }
        printf("%d\n", cnt);
    }
}

/*
    
*/