// https://www.acmicpc.net/problem/24364
// 2022-04-19 20:36:09 152ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    vector<long long> arr(n);
    for(int i=0; i<n; i++)
        scanf("%lld", &arr[i]);
    printf("%lld", (long long)*max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end()));
}

/*

*/