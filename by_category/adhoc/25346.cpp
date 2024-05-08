// https://www.acmicpc.net/problem/25346
// 2024-05-05 09:17:23
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end())-arr.begin());

    if(arr.size()==1)
        // A={0} -> B={1, 1..} -> C={0} -> 1
        // A={1} -> B={0, 0..} -> C={1} -> 0
        return !printf("%d", !arr.front());
    if(arr.front() != 0)
        // A={1, 2, 3..} -> B={0,0...} -> C={1} -> 0
        return !printf("0"); 

    arr.push_back(INT32_MAX);
    for(int i=1; i<arr.size(); i++)
        if(arr[i]-arr[i-1] != 1)
            return !printf("%d", arr[i-1]+3);
}

/*
    0 1 2 3
    1 0 1 2 3 4
    0 1 2 3 4 5 -> 6

    0 1
    0 1 2
    0 1 2 3

    0 3
->  0 1
->  0 1 2
->  3
*/