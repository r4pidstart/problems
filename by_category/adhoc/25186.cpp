// https://www.acmicpc.net/problem/25186
// 2024-05-06 23:12:30
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<long> arr(n);
    for(int i=0; i<n; i++)
        scanf("%ld", &arr[i]);
    
    if(accumulate(arr.begin(), arr.end(), 0L)==1)
        return !printf("Happy");
    
    sort(arr.begin(), arr.end(), greater<>());
    if(arr.front() > accumulate(arr.begin()+1, arr.end(), 0L))
        printf("Unhappy");
    else
        printf("Happy");
}

/*
    
*/