// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    cout.tie(0)->sync_with_stdio(0);
    int k; cin >> k >> k;
    string s; cin >> s;

    deque<char> dq;
    int cnt=0;
    for(int i=0; i<s.length(); i++)
    {
        while(!dq.empty() and cnt!=k and dq.back() < s[i]) dq.pop_back(), cnt++;
        dq.push_back(s[i]);
    }

    for(int i=0; i<s.length()-k; i++)
        cout << dq[i];

    // monotone stack..
    // vector<int> arr(s.length());
    // int prev=0, prevNum=0, cnt=0;
    // for(int i=0; i<s.length(); i++)
    // {
    //     if(s[i] < s[i+1])
    //     {
    //         if(prevNum < s[i+1]) prevNum=s[i+1], prev=0;
    //         for(int j=i; j>=prev; j--)
    //             if(cnt!=k and s[j]<s[i+1] and !arr[j]) cnt++, arr[j]=1;
    //         prev=i;
    //     }
    // }

    // for(int i=0, cnt=0; i<s.length() and cnt<s.length()-k; i++)
    //     if(!arr[i]) cout<<s[i], cnt++;
}

/*
    
*/