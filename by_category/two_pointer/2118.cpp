// https://www.acmicpc.net/problem/2118
// 2022-09-04 01:44:25 8ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int a=0, b=0;
    int dist1=0, dist2=accumulate(arr.begin(), arr.end(), 0), ans=0;
    
    while(a<n)
    {
        int tmp_max=-1;
        while(min(dist1, dist2) > tmp_max)
        {
            tmp_max=min(dist1, dist2);
            if(dist1 < dist2) dist1+=arr[b], dist2-=arr[b], b=(b+1)%n;
            else if(dist1 > dist2) dist1-=arr[(b-1+n)%n], dist2+=arr[(b-1+n)%n], b=(b-1+n)%n;
        }
        ans=max(ans, tmp_max);
        dist1-=arr[a], dist2+=arr[a];
        a++;
    }
    printf("%d", ans);
}

/*
    
*/