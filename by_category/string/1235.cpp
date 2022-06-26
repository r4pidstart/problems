// https://www.acmicpc.net/problem/1235
// 2022-06-27 02:25:28 4ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; cin >> n;
    vector<string> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i], reverse(arr[i].begin(), arr[i].end());

    for(int i=1; i<=100; i++)
    {
        set<string> se;
        for(string s : arr)
            se.insert(s.substr(0, i));
        if(se.size() == n)
        {
            cout << i;
            return 0;
        }
    }
}

/*
    
*/