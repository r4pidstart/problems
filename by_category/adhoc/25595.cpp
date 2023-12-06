// https://www.acmicpc.net/problem/25595
// 2023-12-05 21:17:12
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr;
    int target=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            int a; scanf("%d", &a);
            if(a==2) target=i+j&1;
            if(a==1) arr.push_back(i+j&1);
        }

    sort(arr.begin(), arr.end());
    if(!arr.size() or (arr.front() != target and arr.back() != target))
        printf("Lena");
    else
        printf("Kiriya");

}

/*
    
*/