// https://www.acmicpc.net/problem/23847
// 2022-06-26 03:40:09 16ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> arr(6);
    // II NN UU IN NU IU
    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        int a; cin >> a;
        if(s[0] > s[1]) swap(s[0], s[1]);
        
        if(s=="II") arr[0]+=a;
        else if(s=="NN") arr[1]+=a;
        else if(s=="UU") arr[2]+=a;
        else if(s=="IN") arr[3]+=a;
        else if(s=="NU") arr[4]+=a;
        else if(s=="IU") arr[5]+=a;
    }

    if((arr[3] && arr[4]) or (arr[4] && arr[5]) or (arr[3] && arr[5])) // 두 종류 이상의 연결막대가 존재할 경우
        cout << accumulate(arr.begin(), arr.end(), 0LL);
    else if(arr[3])
        cout << max(arr[0]+arr[1]+arr[3], arr[2]);
    else if(arr[4])
        cout << max(arr[1]+arr[2]+arr[4], arr[0]);
    else if(arr[5])
        cout << max(arr[0]+arr[2]+arr[5], arr[1]);
    else
        cout << max({arr[0], arr[1], arr[2]});
}

/*
    
*/