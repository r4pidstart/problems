// https://www.acmicpc.net/problem/11723
// 2021-05-25 23:06:33 756ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int bitmask=0b0;
    int m, tmp; cin >> m;
    while(m--)
    {
        string s;
        cin >> s;
        if(s=="add")
        {
            cin >> tmp;
            bitmask=bitmask | (1 << tmp-1);
        }
        else if(s=="remove")
        {
            cin >> tmp;
            bitmask=bitmask & ~(1 << tmp-1);
        }
        else if(s=="check")
        {
            cin >> tmp;
            cout << ((bitmask & (1<<tmp-1)) ? 1:0) << '\n';
        }
        else if(s=="toggle")
        {
            cin >> tmp;
            bitmask=bitmask ^ (1 << tmp-1);
        }
        else if(s=="all")
        {   
            bitmask=0b11111111111111111111;
        }
        else if(s=="empty")
        {
            bitmask=0b0;
        }
    }
}