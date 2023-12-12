// https://www.acmicpc.net/problem/20127
// 2023-12-09 23:39:21
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

    int ascending_k=0, descending_k=0;
    for(int i=1; i<n; i++)
    {
        if(arr[i] < arr[i-1] and arr[i-1] >= arr.back())
        {
            ascending_k=i;
            break;
        }
    }
    for(int i=1; i<n; i++)
    {
        if(arr[i] > arr[i-1] and arr[i-1] <= arr.back())
        {
            descending_k=i;
            break;
        }
    }
    
    vector<int> t1(arr.begin()+ascending_k, arr.end());
    vector<int> t2(arr.begin()+descending_k, arr.end());
    for(int i=0; i<ascending_k; i++)
        t1.push_back(arr[i]);
     for(int i=0; i<descending_k; i++)
        t2.push_back(arr[i]);

    vector<int> t1_sorted=t1, t2_sorted=t2;
    
    sort(t1_sorted.begin(), t1_sorted.end());
    sort(t2_sorted.begin(), t2_sorted.end(), greater<int>());

    int flag1=0, flag2=0;
    for(int i=0; i<n; i++)
    {
        if(t1_sorted[i] != t1[i])
        {
            flag1=1;
            break;
        }
    }

    for(int i=0; i<n; i++)
    {
        if(t2_sorted[i] != t2[i])
        {
            flag2=1;
            break;
        }
    }
    if(!flag1 and !flag2)
        return !printf("%d", min(ascending_k, descending_k));
    else if(!flag1)
        return !printf("%d", ascending_k);
    else if(!flag2)
        return !printf("%d", descending_k);
    else    
        return !printf("-1");
}

/*

*/