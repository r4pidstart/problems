// https://www.acmicpc.net/problem/1786
// 2021-05-30 22:57:03 56ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
    vector<int> loca, failure;
    string t,p;
    getline(cin, t);
    getline(cin, p);
    
    int t_len=t.length(), p_len=p.length();

    // get failure function
    failure.assign(p_len, 0);
    int begin=1, m=0;
    while(begin+m < p_len)
    {
        if(p[begin+m]==p[m]) // 같을 경우
        {
            failure[begin+m]=m+1;
            m++;
        }
        else
        {
            if(m==0)
                begin++;
            else
            {
                begin+=m-failure[m-1];
                m=failure[m-1];
            }
        }
    }

    // kmp algorithm
    begin=0, m=0;
    while(begin <= t_len-p_len)
    {
        if(t[begin+m]==p[m] && m<p_len)
        {
            m++;
            if(m==p_len) // 일치하는 문자열 발견
                loca.push_back(begin+1); 
        }
        else
        {
            if(m==0)
                begin++;
            else
            {
                begin+=m-failure[m-1];
                m=failure[m-1];
            }
        }
    }

    cout << loca.size() << '\n';
    for(int location : loca)
        cout << location << ' ';
}
