// https://www.acmicpc.net/problem/16496
// 2021-11-05 05:22:48 4ms
#include<bits/stdc++.h>
using namespace std;

bool comp(string a, string b)
{
    if(a+b > b+a) return 1;
    else return 0;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<string> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end(), comp);
    if(*arr.begin()=="0") cout << 0;
    else
        for(auto it=arr.begin(); it<arr.end(); it++)
            cout << *it;
}

/*
    
*/