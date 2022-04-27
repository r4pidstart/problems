// https://www.acmicpc.net/problem/3047
// 2022-04-27 21:32:30
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int> arr(3);
    for(int i=0; i<3; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());

    string s; cin >> s;
    for(char c : s)
        switch (c)
        {
        case 'A':
            printf("%d ", arr[0]);
            break;
        case 'B':
            printf("%d ", arr[1]);
            break;
        case 'C':
            printf("%d ", arr[2]);
            break;
        }
}

/*
    
*/