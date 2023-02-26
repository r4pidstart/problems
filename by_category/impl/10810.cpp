// https://www.acmicpc.net/problem/10810
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<int> arr(n, 0);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        for(int j=a; j<=b; j++)
            arr[j-1]=c;
    }
    for(auto i : arr)
        printf("%d ", i);
} 

/*
    
*/