// https://www.acmicpc.net/problem/1174
// 2024-01-17 22:35:35
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    vector<long> arr;
    for(int i=1; i<=10; i++)
    {
        vector<int> combi(10);
        fill(combi.begin(), combi.begin()+i, 1);
        do
        {
            long target=0;
            for(int i=9; i>=0; i--)
                if(combi[i]) target=target*10+i;
            arr.push_back(target);
        } while (prev_permutation(combi.begin(), combi.end()));
    }
    
    sort(arr.begin(), arr.end());

    int n; scanf("%d", &n);
    if(n > arr.size()) printf("-1");
    else printf("%ld", arr[n-1]);
}

/*
    
*/