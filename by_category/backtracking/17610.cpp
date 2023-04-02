// https://www.acmicpc.net/problem/17610
// 2023-04-02 18:55:29
#include"bits/stdc++.h"
using namespace std;

void btrk(int sum, int i, vector<int>& arr, vector<int>& ptm)
{
    if(sum >= ptm.size()) return;
    ptm[sum]=1;
    if(i==arr.size()) return;

    btrk(abs(sum-arr[i]), i+1, arr, ptm);
    btrk(sum+arr[i], i+1, arr, ptm);
    btrk(sum, i+1, arr, ptm);
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(n);
    int sum=0;
    for(int& i : arr)
    {
        scanf("%d", &i);
        sum+=i;
    }
    
    vector<int> possible_to_make(sum+1);
    btrk(0, 0, arr, possible_to_make);
    printf("%d", sum-accumulate(possible_to_make.begin(), possible_to_make.end(), 0)+1);   
}

/*
    
*/