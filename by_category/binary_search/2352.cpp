// https://www.acmicpc.net/problem/2352
// 2021-06-23 23:14:33 8ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, ans=0; scanf("%d", &n);
    vector<int> arr(n+1, 0), D(n+1, 0), A;
    A.push_back(0);

    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);
    
    for(int i=1; i<=n; i++)
    {
        vector<int>::iterator it=lower_bound(A.begin(), A.end(), arr[i]);
        auto it2=A.begin();
        if(*it<arr[i])
        {
            D[i]=it-A.begin();
            A.push_back(arr[i]);
        }
        else if(*it==arr[i])
        {
            D[i]=it-A.begin();
        }
        else // if(*it>arr[i])
        {
            D[i]=it-A.begin();
            *it=arr[i];
        }
        ans=max(ans, D[i]);
    }
    printf("%d", ans);
}