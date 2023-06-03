// https://www.acmicpc.net/problem/23970
// 2023-06-04 03:22:45
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for(int j=0; j<n; j++)
        scanf("%d", &b[j]);
    
    if(a==b) return !printf("1");
    
    for(int i=n-1; i>=1; i--)
    {
        for(int j=0; j<n-1; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                if(a[j+1]==b[j+1] and a==b)
                    return !printf("1");
            }
        }
    }
    printf("0");
}

/*
    
*/