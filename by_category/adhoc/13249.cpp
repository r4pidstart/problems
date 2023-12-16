// https://www.acmicpc.net/problem/13249    
// 2023-12-15 22:01:51  
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int t; scanf("%d", &t);

    int ans=0;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(abs(arr[j]-arr[i]) <= 2*t)
                ans++;
    printf("%lf", 1.*ans/4);
}

/*    

*/