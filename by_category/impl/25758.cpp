// https://www.acmicpc.net/problem/25758
// 2022-10-19 00:25:29 40ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);

    vector<string> arr(n);
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++)
        cin >> arr[i];

    vector<int> first(256), second(256);
    for(int i=0; i<n; i++)
        first[arr[i][0]]++, second[arr[i][1]]++;

    vector<char> ans;
    for(auto s : arr)
    {
        first[s[0]]--;
        second[s[1]]--;

        int flag_first=0, flag_second=0;
        for(int i='A'; i<=s[0]; i++)
            if(second[i]) flag_first++;
        for(int i='A'; i<=s[1]; i++)
            if(first[i]) flag_second++;

        if(flag_first) ans.push_back(s[0]);
        if(flag_second) ans.push_back(s[1]);

        first[s[0]]++;
        second[s[1]]++;
    }

    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end())-ans.begin());
    printf("%lu\n", ans.size());
    for(auto c : ans)
        printf("%c ", c);
}

/*
    
*/