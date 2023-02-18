// https://www.acmicpc.net/problem/27468
// 2023-02-19 03:35:06
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(max(4, n));

    if(n&1)
        arr[0]=1, arr[1]=3, arr[2]=2, arr[3]=4;
    else
        arr[0]=2, arr[1]=1, arr[2]=3, arr[3]=4;

    for(int i=0; i<4; i++)
        for(int k=1, j=i+4; j<n; j+=4, k++)
            arr[j]=arr[i]+k*4;
    
    printf("YES\n");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
}

/*
    1 3 2 4 / 5 7 6 8 / ... -> n&1
    2 1 3 4 / 6 5 7 8 / ...
*/