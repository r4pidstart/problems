// https://www.acmicpc.net/problem/10820
// 2022-03-22 21:45:38 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s;
    while(getline(cin, s))
    {
        int lo=0, up=0, nu=0, ws=0;
        for(char c : s)
            if(islower(c)) lo++;
            else if(isupper(c)) up++;
            else if(isdigit(c)) nu++;
            else if(c==' ') ws++;
        printf("%d %d %d %d\n", lo, up, nu, ws);
    }
}

/*
    
*/