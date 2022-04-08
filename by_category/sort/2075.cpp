// https://www.acmicpc.net/problem/2075
// 2022-04-09 02:28:29 408ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(NULL)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n*n);
    for(int i=0; i<n*n; i++)
        cin >> arr[i][j];
    sort(arr.begin(), arr.end());
    cout << *(arr.end()-n);
}

/*
    
*/