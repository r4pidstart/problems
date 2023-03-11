// https://www.acmicpc.net/problem/21762
// 2023-03-11 14:56:49
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    while(n--)
    {
        string a,b,x; cin >> a >> b >> x;

        vector<int> last_idx_a(x.size()), last_idx_b(x.size());
        {
            int idx_x=x.size()-1, idx_a=a.size()-1;
            while(idx_x >= 0)
            {
                if(a[idx_a] == x[idx_x]) last_idx_a[idx_x--]=idx_a;
                idx_a--;
            }
        }
        {
            int idx_x=x.size()-1, idx_b=b.size()-1;
            while(idx_x >= 0)
            {
                if(b[idx_b] == x[idx_x]) last_idx_b[idx_x--]=idx_b;
                idx_b--;
            }
        }

        vector<int> first_idx_a(x.size()+1, -1), first_idx_b(x.size()+1, -1);
        {
            int idx_x=0, idx_a=0;
            while(idx_x < x.size())
            {
                if(a[idx_a] == x[idx_x]) first_idx_a[idx_x++ +1]=idx_a;
                idx_a++;
            }
        }
        {
            int idx_x=0, idx_b=0;
            while(idx_x < x.size())
            {
                if(b[idx_b] == x[idx_x]) first_idx_b[idx_x++ +1]=idx_b;
                idx_b++;
            }
        }

        last_idx_a.push_back(a.size()), last_idx_b.push_back(b.size());

        int lo_a=0, hi_a=0, lo_b=0, hi_b=0;

        vector<int> char_table_a(26), char_table_b(26);

        int idx=-1, flag=0;
        while(++idx <= x.size())
        {
            // (lo_a, hi_a)
            while(hi_a < last_idx_a[idx]) char_table_a[a[hi_a++]-'a']++;
            while(hi_b < last_idx_b[idx]) char_table_b[b[hi_b++]-'a']++;

            while(lo_a <= first_idx_a[idx]) char_table_a[a[lo_a++]-'a']--;
            while(lo_b <= first_idx_b[idx]) char_table_b[b[lo_b++]-'a']--;

            for(int i=0; i<26; i++)
                if(char_table_a[i] and char_table_b[i]) flag=1;
            if(flag) break;
        }

        if(flag) printf("1\n");
        else printf("0\n");
    }
}

/*
    
*/