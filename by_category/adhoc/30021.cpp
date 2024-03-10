// https://www.acmicpc.net/problem/30021
// 2024-03-09 20:34:13
#include"bits/stdc++.h"
using namespace std;

int is_prime(int n)
{
    if(n==1)
        return 0;
    for(int i=2; 1L*i*i<n; i++)
        if(n%i==0) return 0;
    return 1;
}
int main(void)
{
    int n; scanf("%d", &n);
    if(n==2)
        return !printf("NO");

    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    swap(arr[1], arr[2]);

    printf("YES\n");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
}

/*
    
*/