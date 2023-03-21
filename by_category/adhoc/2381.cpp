// https://www.acmicpc.net/problem/2381
// 2023-03-22 00:12:36
#include"bits/stdc++.h"
using namespace std;

int get_dist(const pair<int,int>& p1, const pair<int,int>& p2)
{
    return abs(p1.first-p2.first)+abs(p1.second-p2.second);
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr1, arr2;
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        arr1.push_back(a+b);
        arr2.push_back(a-b);
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    printf("%d", max(arr1.back()-arr1.front(), arr2.back()-arr2.front()));
}

/*
    p1(a,b), p2(c,d)
    sort -> a<c

    if(b<d) -> c-a + d-b = (c+d) - (a+b)
    else -> c-a + b-d = (c-d) - (a-b)

*/