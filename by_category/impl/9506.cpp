// https://www.acmicpc.net/problem/9506
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    while(true)
    {
        int n; scanf("%d", &n);
        if(n==-1) break;

        vector<int> arr;
        for(int i=1; i<n; i++)
            if(n%i==0) arr.push_back(i);
        if(accumulate(arr.begin(), arr.end(), 0)==n)
        {
            printf("%d = ", n);
            for(int i=0; i<arr.size()-1; i++)
                printf("%d + ", arr[i]);
            printf("%d\n", arr.back());
        }
        else
        {
            printf("%d is NOT perfect.\n", n);
        }
    }
}

/*
    
*/