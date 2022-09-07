// https://www.acmicpc.net/problem/3649
// 2022-09-08 01:57:35 1712ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n, x;
    start:
    while(scanf("%d%d", &x, &n) != EOF)
    {
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        sort(arr.begin(), arr.end());

        for(int i=0; i<n; i++)
        {
            auto it=lower_bound(arr.begin(), arr.end(), x*10000000 - arr[i]);
            if(it != arr.end() and it-arr.begin() != i and *it == x*10000000 - arr[i])
            {
                printf("yes %d %d\n", arr[i], *it);
                goto start;
            }
        }
        printf("danger\n");
    }
}

/*
    
*/