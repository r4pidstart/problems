// https://www.acmicpc.net/problem/2631
// 2021-08-23 02:46:59 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> lis;
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        auto it=lower_bound(lis.begin(), lis.end(), a);
        if(it == lis.end())
            lis.push_back(a);
        else
            *it=a;
    }
    printf("%ld", n-lis.size());
}

/*

*/