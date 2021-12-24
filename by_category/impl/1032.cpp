// https://www.acmicpc.net/problem/1032
// 2021-12-25 05:56:06 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    setbuf(stdout, NULL);
    int n; cin >> n;
    vector<string> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    vector<int> ans(arr[0].length());
    for(int i=1; i<n; i++)
        for(int j=0; j<arr[0].length(); j++)
            if(arr[0][j] != arr[i][j]) ans[j]=1;
    
    for(int i=0; i<arr[0].length(); i++)
    {
        if(ans[i]) cout << '?';
        else cout << arr[0][i];
    }
}

/*
    
*/