// https://www.acmicpc.net/problem/2475
// 2022-03-08 19:41:56 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    array<int,5> arr;
    for(int i=0; i<5; i++)
        scanf("%d", &arr[i]);

    for(auto& i : arr)
        i*=i;
    printf("%lld", accumulate(arr.begin(), arr.end(), 0LL)%10);
}

/*
    
*/