// https://www.acmicpc.net/problem/16455
// 2022-10-11 00:43:54 56ms
#include"bits/stdc++.h"
using namespace std;

int dc(std::vector<int> &a, int s, int e, int k)
{
    if(e-s)
    {
        srand(time(NULL));
        swap(a[s], a[rand()%(e-s) + s]);
    }
    int pivot=a[s];
    int l=s, r=e;
    while(l<r)
    {
        while(pivot < a[r]) r--;
        while(l<r && pivot >= a[l]) l++;
        swap(a[l], a[r]);
    }
    swap(a[s], a[l]);
    if(l == k)
        return a[r];
    else if(l > k)
        return dc(a, s, r-1, k);
    else
        return dc(a, r+1, e, k);
}

int kth(std::vector<int> &a, int k)
{
    // return dc(a, 0, a.size()-1, k-1);
    nth_element(a.begin(), a.begin()+k-1, a.end());
    return a[k-1];
}

int main(void)
{
    srand(time(NULL));
    vector<int> arr(5000000);
    for(int i=0; i<5000000; i++)
        arr[i]=rand()%500000;
    nth_element(arr.begin(), arr.begin()+4000000, arr.end());
    printf("%d", arr[4000000]);
}

/*
    
*/