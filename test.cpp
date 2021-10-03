// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s, bomb, str=""; cin >> s >> bomb;
    for(int i=0; i<(int)s.length(); i++)
    {
        str.push_back(s[i]);
        if(str[i]==bomb[bomb.length()-1])
        {
            if(i < bomb.length()-1) continue;
            int flag=0;
            for(int j=0; j<bomb.length(); j++)
                if(str[i-bomb.length()+j+1]!=bomb[j])
                {
                    flag++;
                    break;
                }
            if(!flag) 
            {
                for(int j=0; j<bomb.length(); j++) str.pop_back();
                i--;
            }
        }
    }
    if(str.empty()) printf("FRULA");
    else cout << str;
}

/*
    
*/