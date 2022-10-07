// https://www.acmicpc.net/problem/11509
// 2022-10-08 02:12:32 108ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(1'000'001);
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        if(arr[a]) arr[a]--, arr[a-1]++;
        else arr[a-1]++;
    }
    printf("%d", accumulate(arr.begin(), arr.end(), 0));
}

/*
    
*/