// https://www.acmicpc.net/problem/1038
// 2024-03-05 22:25:09
#include"bits/stdc++.h"
using namespace std;

int solution(long now, vector<long>& arr)
{
    arr.push_back(now);
    if(!now)
        for(int i=1; i<=9; i++)
            solution(i, arr);
    
    for(int i=0; i<now%10; i++)
        solution(now*10+i, arr);
    return 0;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<long> arr;
    solution(0, arr);

    sort(arr.begin(), arr.end());
    if(n>=arr.size())
        return !printf("-1");
    else
        return !printf("%ld", arr[n]);
}

/*
    
*/