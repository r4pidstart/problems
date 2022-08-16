// https://www.acmicpc.net/problem/14225
// 2022-08-16 22:07:32 348ms
#include"bits/stdc++.h"
using namespace std;

void bf(int i, int sum, set<int>& se, vector<int>& arr)
{
    if(sum!=0)
        se.insert(sum);
    if(i == arr.size())
        return;
    
    bf(i+1, sum+arr[i], se, arr);
    bf(i+1, sum, se, arr);
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    set<int> se;

    bf(0, 0, se, arr);

    int a=0;
    while(++a)
        if(se.find(a) == se.end())
            return !printf("%d", a);
}

/*
    
*/