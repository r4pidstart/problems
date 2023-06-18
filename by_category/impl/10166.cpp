// https://www.acmicpc.net/problem/10166
// 2023-06-18 09:24:31
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int a,b; scanf("%d%d", &a, &b);
    vector<double> arr;

    for(int i=a; i<=b; i++)
    {
        double tmp=0;
        for(int j=0; j<i; j++)
        {
            arr.push_back(tmp);
            tmp+=360./i;
        }
    }
    sort(arr.begin(), arr.end());
    int cnt=0;
    double prev=-1;
    for(double a : arr)
    {
        if(abs(a-prev) > 1e-7)
            cnt++, prev=a;
    }
    printf("%d", cnt);
}

/*
    
*/