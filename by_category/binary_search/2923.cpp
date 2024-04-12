// https://www.acmicpc.net/problem/2923
// 2024-04-12 20:25:16
#include"bits/stdc++.h"
using namespace std;

int decision(vector<int> a, vector<int> b, int n)
{
    int cur=n-1;
    for(int i=1; i<=100; i++)
    {
        if(!a[i]) continue;
        while(a[i])
        {
            while(cur and !b[cur]) cur--;
            if(!cur or i+cur > n)
                return 0; // cannot be matched
            
            if(a[i] > b[cur])
                a[i]-=b[cur], b[cur]=0;
            else
                b[cur]-=a[i], a[i]=0;
        }
    }
    return 1;
}

int optimize(const vector<int>& a, const vector<int>& b)
{
    int lo=2, hi=200, ans=200;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(decision(a, b, mid))
            hi=mid-1, ans=mid;
        else
            lo=mid+1;
    }
    return ans;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr1(201), arr2(201);
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        arr1[a]++, arr2[b]++;
        printf("%d\n", optimize(arr1, arr2));
    }
}

/*
    
*/