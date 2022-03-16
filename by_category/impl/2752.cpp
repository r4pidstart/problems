// https://www.acmicpc.net/problem/2752
// 2022-03-16 23:32:57 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr+3);
    printf("%d %d %d", arr[0], arr[1], arr[2]);
}

/*
    
*/