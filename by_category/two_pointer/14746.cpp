// https://www.acmicpc.net/problem/14746
// 2023-12-30 15:42:42
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    int c1,c2; scanf("%d%d", &c1, &c2);

    vector<int> arr1(n), arr2(m);
    for(int i=0; i<n; i++)
        scanf("%d", &arr1[i]);
    for(int i=0; i<m; i++)
        scanf("%d", &arr2[i]);
    
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int ans=INT32_MAX, cnt=0;
    int i1=0, i2=0;
    while(i1<n and i2<m)
    {
        if(abs(arr1[i1]-arr2[i2]) < ans)
            ans=abs(arr1[i1]-arr2[i2]), cnt=1;
        else if(abs(arr1[i1]-arr2[i2]) == ans)
            cnt++;
        
        if(arr1[i1] < arr2[i2]) i1++;
        else i2++;
    }
    printf("%d %d", ans+abs(c1-c2), cnt);
}

/*
  
*/