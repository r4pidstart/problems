// https://www.acmicpc.net/problem/23321
// 2021-11-01 23:58:12 B
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<string> arr(5);
    for(int i=0; i<5; i++) cin >> arr[i];

    for(int i=0; i<arr[0].size(); i++)
    {
        if(arr[1][i]=='o') // 도약 준비
        {
            arr[0][i]='o', arr[1][i]='w', arr[2][i]='l', arr[3][i]='n', arr[4][i]='.';
        }
        else if(arr[1][i]=='w') // 도약 중
        {
            arr[0][i]='.', arr[1][i]='o', arr[2][i]='m', arr[3][i]='l', arr[4][i]='n';
        }
    }
    for(string& s : arr)
        cout << s << '\n';
}

/*
    
*/