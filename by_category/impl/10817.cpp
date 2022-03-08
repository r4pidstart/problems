// https://www.acmicpc.net/problem/10817
// 2022-03-08 18:57:33 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int arr[3]; scanf("%d%d%d", &arr[0],&arr[1],&arr[2]);
    sort(arr, arr+3);
    printf("%d", arr[1]);
}

/*
    
*/