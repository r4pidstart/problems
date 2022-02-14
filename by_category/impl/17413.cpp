// https://www.acmicpc.net/problem/17413
// 2022-02-14 23:10:20 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; 
    getline(cin, s);
    for(int i=0; i<s.length(); i++)
    {
        // tag
        if(s[i] == '<')
            while(s[++i] != '>');
        // word
        else if(s[i] != ' ')
        {
            int word_start=i;
            while(s[++i] != ' ' && s[i] != '\0' && s[i] != '<');
            reverse(s.begin()+word_start, s.begin()+i--);
        }
    }
    cout << s;
}

/*
    
*/