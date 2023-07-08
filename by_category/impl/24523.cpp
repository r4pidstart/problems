// https://www.acmicpc.net/problem/24523
// 2023-07-09 03:13:48
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(n), ans(n, -1);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    int p_start=0;
    for(int i=1; i<n; i++)
        if(arr[i] != arr[p_start])
        {
            for(int j=p_start; j<i; j++)
                ans[j]=i+1;
            p_start=i;
        }
    
    for(auto i : ans)   
        printf("%d ", i);
}

/*
    
*/

/*
 
// https://www.acmicpc.net/problem/
// 
#include<stdio.h>

int main(void)
{
    int a[2][2]=
    {
        {3, 2},
        {1, 4}
    };
    int b[2][2]=
    {
        {7, 8},
        {6, 4}
    };

    int ret[2][2];
    for(int i=0; i<sizeof(a)/sizeof(int*); i++)
        for(int j=0; j<sizeof(b)/sizeof(int*); j++)
        {

        }
}
   
*/