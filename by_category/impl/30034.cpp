// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int a; scanf("%d", &a);
    set<char> se1;
    for(int i=0; i<a; i++)
    {
        char a; scanf(" %c", &a);
        se1.insert(a);
    }
    int b; scanf("%d", &b);
    for(int i=0; i<b; i++)
    {
        char a; scanf(" %c", &a);
        se1.insert(a);
    }

    int c; scanf("%d", &c);
    set<char> se2;
    for(int i=0; i<c; i++)
    {
        char c; scanf(" %c", &c);
        se2.insert(c);
        se1.erase(c);
    }   
    se1.insert(' ');

    int n; scanf("%d", &n);
    string tmp="";
    vector<string> arr;
    cin >> ws;
    for(int i=0; i<n; i++)
    {
        char c;
        scanf("%c", &c);
        if(se1.find(c) != se1.end())
        {
            if(tmp != "")
                arr.push_back(tmp);
            // arr.push_back(string(1, c));
            tmp="";
        }
        else
            tmp+=c;
    }
    arr.push_back(tmp);

    for(string s : arr)
        printf("%s\n", s.c_str());

    // for(string s : tmp)
    // {
    //     int flag=0;
    //     for(char c : s)
    //         if(se2.find(c) != se2.end())
    //         {
    //             if(!flag)
    //                 cout << c << '\n';
    //             flag++;
    //         }
    //     assert(flag<2);
    //     if(!flag)
    //         cout << s << '\n';
    // }
}

/*
    
*/