// https://www.acmicpc.net/problem/18310
// 2022-08-21 20:43:12
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    printf("%d", arr[(n-1)/2]);
}

/*
    
*/