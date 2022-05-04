// https://www.acmicpc.net/problem/1138
// 2022-05-05 01:26:31 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        for(int j=0; j<n; j++)
        {
            if(!a and !arr[j]) arr[j]=i+1, a=-1;
            if(!arr[j]) a--;
        }
    }
    for(int i : arr)
        printf("%d ", i);
}

/*
    
*/