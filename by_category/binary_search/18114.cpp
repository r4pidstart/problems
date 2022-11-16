// https://www.acmicpc.net/problem/18114
// 2022-11-17 00:44:54 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,c; scanf("%d%d", &n, &c);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i] == c)
            return !printf("1");
    }
    
    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
        {
            if(binary_search(arr.begin()+i+1, arr.end(), c-arr[i]-arr[j]))
                return !printf("1");
            if(arr[i]+arr[j] == c)
                return !printf("1");
        }

    printf("0");
}

/*
    
*/