// https://www.acmicpc.net/problem/1431 
// 2022-04-08 01:14:23 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<string> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end(), [](string a, string b) -> bool
    {
        if(a.length() == b.length())
        {
            int ac=0, bc=0;
            for(auto c : a) isdigit(c) ? ac+=c-'0' : 0;
            for(auto c : b) isdigit(c) ? bc+=c-'0' : 0;

            if(ac == bc)
                return a < b;
            else return ac < bc;
        }
        else return a.length() < b.length();
    });
    for(auto s : arr)
        cout << s << '\n';
}

/*
    
*/