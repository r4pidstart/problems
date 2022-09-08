// https://www.acmicpc.net/problem/20115
// 2022-09-09 02:48:40 28ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());

    printf("%lf", arr[n-1]+accumulate(arr.begin(), arr.end()-1, 0L)/2.0);
}

/*
    
*/