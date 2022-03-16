// https://www.acmicpc.net/problem/1406
// 2022-03-16 00:31:41 108ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    list<char> lst;
    for(auto c : s)
        lst.push_back(c);
    auto cur=lst.end();
    int n; scanf("%d", &n);
    while(n--)
    {
        char c; scanf(" %c", &c);
        switch (c)
        {
        case 'L':
            if(cur!=lst.begin()) cur--;
            break;

        case 'D':
            if(cur!=lst.end()) cur++;
            break;

        case 'B':
            if(cur!=lst.begin())
                cur=lst.erase(--cur);
            break;

        case 'P':
            char input; scanf(" %c", &input);
            lst.insert(cur, input);
            break;
        }
    }
    for(auto c : lst)
        printf("%c", c);
}

/*
    
*/