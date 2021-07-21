// https://www.acmicpc.net/problem/12738
// 2021-07-22 01:03:14 284ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(0,0);
    for(int i=0; i<n; i++)
    {
        int tmp; scanf("%d", &tmp);
        auto it=lower_bound(arr.begin(), arr.end(), tmp);
        if(it==arr.end())
            arr.push_back(tmp);
        else
            *it=min(*it, tmp);
    }
    printf("%ld", arr.size());
}

/*

*/
