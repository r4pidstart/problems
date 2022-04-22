// https://www.acmicpc.net/problem/11034
// 2022-04-22 23:46:35 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int arr[3]; 
    while(scanf("%d%d%d", &arr[0], &arr[1], &arr[2]) != EOF)
    {
        sort(arr, arr+3);
        int ans=max(arr[1]-arr[0]-1, arr[2]-arr[1]-1);
        printf("%d\n", ans);
    }
}

/*
    
*/