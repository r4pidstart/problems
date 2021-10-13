// https://www.acmicpc.net/problem/23246
// 2021-10-14 05:29:15 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,pair<int,int> > > arr(n);
    for(int i=0; i<n; i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        arr[i]={b*c*d,{b+c+d, a}};
    }
    sort(arr.begin(), arr.end());
    printf("%d %d %d", arr[0].second.second, arr[1].second.second, arr[2].second.second);
}