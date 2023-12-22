// https://www.acmicpc.net/problem/
// 
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
    sort(arr.begin(), arr.end());

    if(n<2) printf("%d", arr[0]);
    else printf("%.10lf", max(1.*arr[n-2], accumulate(arr.begin(), arr.end(), 0.)/n));

}

/*

*/