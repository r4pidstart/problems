// https://www.acmicpc.net/problem/17214
// 2022-08-04 01:11:21 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    string s; cin >> s;
    if(s=="0") return !printf("W");
    int sign2_loca=0, num1=0, num2=0, degree1=0;
    
    num1=atoi(s.c_str());
    for(auto i : s)
        if(i == 'x') degree1++;

    if(degree1)
    {
        for(int i=1; i<s.length(); i++)
            if(s[i] == '+' or s[i] == '-') sign2_loca=i;
        num2=atoi(s.substr(sign2_loca).c_str());
    }

    if(degree1)
    {
        if(num1 / 2 != 1 and num1 / 2 != -1) cout << num1/2;
        else if(num1 / 2 == -1) cout << '-';
        cout << "xx";

        if(sign2_loca)
        {
            if(num2 > 0) cout << '+';
            else if(num2 == -1) cout << '-';
            if(num2 != 1 and num2 != -1) cout << num2;
            cout << "x";
        }
    }
    else
    {
        if(num1 != 1 and num1 != -1) cout << num1;
        else if(num1 == -1) cout << '-';
        cout << "x";
    }

    cout << "+W";
}

/*
    
*/