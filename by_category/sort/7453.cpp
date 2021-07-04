// https://www.acmicpc.net/problem/7453
// 2021-07-05 03:47:20 6640ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > arr(4, vector<int>(n));
    for(int j=0; j<n; j++)
        for(int i=0; i<4; i++)
            scanf("%d", &arr[i][j]);

    deque<int> sumA, sumB;

    for(int a : arr[0])
        for(int b : arr[1])
            sumA.push_back(a+b);

    for(int a : arr[2])
        for(int b : arr[3])
            sumB.push_back(a+b);

    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end());

    long long count=0;
    for(auto& A : sumA)
    {
        auto it1=upper_bound(sumB.begin(), sumB.end(), -A),
            it2=lower_bound(sumB.begin(), sumB.end(), -A);
        count+=it1-it2;
    }

    printf("%lld", count);
}

/*

*/