// https://www.acmicpc.net/problem/20154
// 2023-05-02 03:04:46
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    const int cnt[]={3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1,};
    string s; cin >> s;

    list<int> lst;
    for(char c : s) lst.push_back(cnt[c-'A']);
    while(lst.size() != 1)
    {
        list<int> tmp=lst;
        lst.clear();

        while(tmp.size() >= 2)
            lst.push_back((*tmp.begin()+*++tmp.begin()) % 10), tmp.pop_front(), tmp.pop_front();
        while(tmp.size())
            lst.push_back(tmp.front()), tmp.pop_front();
    }
    printf(lst.front()&1 ? "I'm a winner!" : "You're the winner?");
}

/*
    
*/