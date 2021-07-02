// 7-2 QUADTREE
// https://algospot.com/judge/problem/read/QUADTREE
// 2021-07-03 03:06:44 8ms
#include<bits/stdc++.h>
using namespace std;

string quadtree_reverse(string::iterator& it)
{
    char head=*(it++);

    if(head!='x')
        return string(1, head);
    else
    {
        string _1=quadtree_reverse(it);
        string _2=quadtree_reverse(it);
        string _3=quadtree_reverse(it);
        string _4=quadtree_reverse(it);

        return string(1, 'x')+_3+_4+_1+_2; 
    }
}

int main(void)
{
    int c; scanf("%d", &c);
    while(c--)
    {
        string s; cin>>s;
        string::iterator it=s.begin();
        string ans=quadtree_reverse(it);
        cout << ans << '\n';
    }
}

/*

*/