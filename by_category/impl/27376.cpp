// https://www.acmicpc.net/problem/27376
// 2023-02-09 03:48:59
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,k;
    scanf("%d%d", &n, &k);

    vector<pair<int, pair<int,int> > > arr(k);
    for(int i=0; i<k; i++)
        scanf("%d%d%d", &arr[i].first, &arr[i].second.first, &arr[i].second.second);
    sort(arr.begin(), arr.end());

    long t=0, x=0; 
    for(int i=0; i<k; i++)
    {
        t+=arr[i].first-x;
        x=arr[i].first;

        if(t<arr[i].second.second)
            t=arr[i].second.second;
        
        if((t-arr[i].second.second)/arr[i].second.first & 1)
            t+=((t-arr[i].second.second)/arr[i].second.first+1)*arr[i].second.first - (t-arr[i].second.second);

        t++, x++;
    }
    t+=n-x;
    printf("%ld", t);
}

/*
    
*/