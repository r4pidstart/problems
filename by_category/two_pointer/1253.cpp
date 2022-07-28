// https://www.acmicpc.net/problem/1253
// 2022-07-29 01:12:46 16ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());

    int cnt=0;
    map<int, int> dp;
    for(int k=0; k<n; k++)
    {
        if(dp.find(arr[k]) != dp.end())
        {
            cnt+=dp[arr[k]];
            continue;
        }
        int s=0, e=n-1;
        while(s<e)
        {
            if(s==k)
            {
                s++;
                continue;
            }
            if(e==k)
            {
                e--;
                continue;
            }

            if(arr[s]+arr[e] < arr[k])
                s++;
            else if(arr[s]+arr[e] > arr[k])
                e--;
            else
                goto good_number;
        }
        continue;
        good_number:
            cnt++, dp[arr[k]]=1;
    }

    cout << cnt;
}

/*
    
*/