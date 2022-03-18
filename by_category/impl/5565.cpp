// https://www.acmicpc.net/problem/5565
// 2022-03-18 23:36:52 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int sum; scanf("%d", &sum);
    vector<int> arr(9);
    for(int i=0; i<9; i++)
        scanf("%d", &arr[i]);
    printf("%d", sum-accumulate(arr.begin(), arr.end(), 0));
}

/*
    
*/