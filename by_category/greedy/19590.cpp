// https://www.acmicpc.net/problem/19590
// 2024-05-23 00:09:55
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<>());

    long a=0, b=0;
    for(int i=0; i<n; i++)
    {
        if(a>b)
            swap(a,b);

        if(a+arr[i] <= b)
            a+=arr[i];
        else
        {
            long dif=abs(a-b);
            long remain=arr[i]-dif;
            long tmp=min(remain/2, a);
            a+=dif;
            b+=tmp;
            a+=remain-tmp;
        }        
    }
    cout << abs(a-b);
}

/*
    10 10 10 
    5 5 10
    0

    10 5 5 5 5
    5 5 5 5
    5 5
    0
*/