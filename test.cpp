// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int> arr;
    for(int i=0, n=1; i<1000; n++)
        for(int j=0; j<n; j++, i++)
            arr.push_back(n);

    int a,b; scanf("%d%d", &a, &b);
    printf("%d", accumulate(&arr[a-1], &arr[b], 0));
}

/*
    
*/