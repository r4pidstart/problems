// https://www.acmicpc.net/problem/2560
// 2024-02-07 03:29:37
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int a,b,d,n; scanf("%d%d%d%d", &a, &b, &d, &n);
    
    long baby=0, adult_1=0, adult_0=0;
    vector<long> arr(n+1);
    arr[0]=1;
    baby=1;
    for(int i=1; i<=n; i++)
    {
        if(i>=d) // death count
            adult_0=(adult_0+1000-arr[i-d])%1000;
        if(i>=a) // adult promotion
            adult_1=(adult_1+arr[i-a])%1000, baby=(baby+1000-arr[i-a])%1000;
        if(i>=b)
            adult_0=(adult_0+arr[i-b])%1000, adult_1=(adult_1+1000-arr[i-b])%1000;
        arr[i]=adult_1; // born on ith day
        baby+=arr[i];
    }
    
    printf("%ld", (adult_0+adult_1+baby)%1000);
}

/*
    
*/