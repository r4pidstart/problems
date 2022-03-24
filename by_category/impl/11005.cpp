// https://www.acmicpc.net/problem/11005
// 2022-03-25 00:29:11 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a,b; cin >> a >> b;
    string s;
    while(a)
    {
        char tmp=a%b;
        if(tmp > 9) tmp+='A'-10;
        else tmp+='0';
        s+=tmp;
        a/=b;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

/*
    
*/