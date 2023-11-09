// https://www.acmicpc.net/problem/14467
// 2023-11-04 00:50:20
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(11, -1);

    int cnt=0;
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        if(arr[a]==-1)
            arr[a]=b;
        else if(arr[a]!=b)
            cnt++, arr[a]^=1;    
    }
    printf("%d", cnt);
}

/*
    
*/