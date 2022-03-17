// https://www.acmicpc.net/problem/10974
// 2022-03-17 15:15:02 24ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        arr[i]=i+1;
    do
    {
        for(int i : arr)
            printf("%d ", i);
        printf("\n");
        /* code */
    } while (next_permutation(arr.begin(), arr.end()));
    
}

/*
    
*/