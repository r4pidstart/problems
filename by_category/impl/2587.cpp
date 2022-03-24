// https://www.acmicpc.net/problem/2587
// 2022-03-25 00:21:31 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int> arr(5);
    for(int i=0; i<5; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    printf("%d\n%d", accumulate(arr.begin(), arr.end(), 0)/5, arr[2]);
}

/*
    
*/