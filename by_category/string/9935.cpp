// https://www.acmicpc.net/problem/9935
// 2021-10-04 05:23:55 80ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s, bomb; cin >> s >> bomb;
    deque<char> stk, stk2;
    for(int i=0; i<s.length(); i++)
    {
        stk.push_back(s[i]);

        // 폭탄 문자열의 마지막 글자를 만나면, 하나씩 빼면서 폭탄문자열인지 확인
        if(s[i]==bomb[bomb.size()-1])
        {
            int flag=0;
            for(int j=bomb.size()-1; j>=0; j--)
            {
                if(stk.empty()) flag++;
                if(!flag && stk.back()==bomb[j])
                {
                    stk2.push_front(stk.back());
                    stk.pop_back();
                }
                else flag++;
            }

            while(!stk2.empty())
            {
                if(flag) stk.push_back(stk2.front());
                stk2.pop_front();
            }
        }
    }

    if(stk.empty()) printf("FRULA");
    else while(!stk.empty())
    {
        printf("%c", stk.front());
        stk.pop_front();
    }
}

/*
    
*/