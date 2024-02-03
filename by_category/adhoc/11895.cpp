// https://www.acmicpc.net/problem/11895
// 2024-02-04 02:43:20
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(32);
    int ans=0, mi=INT32_MAX;
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        bitset<32> bi(a);
        for(int j=0; j<32; j++)
            if(bi[j]) arr[j]++;
        ans+=a;
        mi=min(mi, a);
    }

    for(int i=0; i<32; i++)
        if(arr[i] & 1)
            return !printf("0");
    printf("%d", ans-mi);
}

/*
    
*/