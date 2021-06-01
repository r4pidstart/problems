

#include<bits/stdc++.h>
using namespace std;

int check(string s, string pattern, int index)
{
    int p_len=pattern.length();

    for(int i=0; i<p_len; i++)
        if(s[index+i]!=pattern[i])
            return 0;
    return 1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    while(s != ".")
    {
        int cur_s=1, cur_p=0, s_len=s.length(), count=1, ans=1;
        string pattern=s.substr(0,1);
        while(cur_s < s_len)
        {
            if(s[cur_s++] != pattern[cur_p++])
            {
                // 새로운 패턴 만들기
                int prev_p_len=pattern.length();
                pattern=s.substr(0, cur_s);

                for(int i=1; i<=prev_p_len; i++)
                    if(check(s, s.substr(0, cur_s-i), cur_s-i))
                    {
                        pattern=s.substr(0, cur_s-i), cur_s-=i;
                        break;
                    }

                cur_p=0, count=1;
            }
            else
            {
                if(cur_p==pattern.length())
                    cur_p=0, count++, ans=count;
                else
                    ans=1; // 문자열 완결 안됨
            }
        }
        cout << ans << '\n';
        cin >> s;
    }
}
