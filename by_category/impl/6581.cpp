// https://www.acmicpc.net/problem/6581
// 2024-04-27 22:46:15
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    string s;
    int cnt=0;
    while(getline(cin, s))
    {
        stringstream ss(s);
        string s;
        while(ss >> s)
        {
            if(s=="<br>")
                printf("\n"), cnt=0;
            else if(s=="<hr>")
            {
                if(cnt)
                    printf("\n");
                printf("--------------------------------------------------------------------------------\n");
                cnt=0;
            }
            else
            {
                if(cnt+s.size()+1 > 80)
                    printf("\n"), cnt=0;
                if(cnt)
                    printf(" "), cnt++;
                printf("%s", s.c_str());
                cnt+=s.size();
            }
        }
    }
    printf("\n");
}

/*
    
*/