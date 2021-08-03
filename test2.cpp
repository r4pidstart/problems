// https://www.acmicpc.net/problem/
// 
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s[10]=
    {
        "99999","9988","99","12345","987"
    };
    sort(s, s+10);
    
    for(string i : s)
        cout << i << '\n';
}

/*

*/