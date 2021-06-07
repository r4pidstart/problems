// https://www.acmicpc.net/problem/4354
// 2021-06-01 01:42:31 92ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    while(s!=".")
    {
        int s_len=s.length(), begin=1, m=0;
        vector<int> pi(s_len,0);
        while(begin+m < s_len)
        {
            if(s[begin+m]==s[m])
            {
                m++;
                pi[begin+m-1]=m;
            }
            else
            {
                if(m==0)
                    begin++;
                else
                {
                    begin+=m-pi[m-1];
                    m=pi[m-1];
                }
            }
        }
        if(pi[s_len-1]%(s_len-pi[s_len-1]))
            cout << "1" << '\n';
        else
            cout << s_len/(s_len-pi[s_len-1]) << '\n';
        cin >> s;
    }
}
