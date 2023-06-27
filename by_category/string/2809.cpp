// https://www.acmicpc.net/problem/2809
// 2023-06-27 10:15:22
#include"bits/stdc++.h"
using namespace std;

struct Aho
{
    static Aho* root;
    map<char, Aho*> next;
    int max_len;

    Aho* failure;
    Aho() { max_len=0; }
    Aho(int) { Aho::root=this; max_len=0; }
    ~Aho()
    {
        for(auto [c, n] : next)
            delete n;
    }

    void insert(const string& s, size_t idx=0)
    {
        char nc=s[idx];
        if(nc=='\0')
        {
            max_len=max(max_len, (int)s.length());
            return;
        }
        else if(!next[nc]) 
            next[nc]=new Aho();
        next[nc]->insert(s, idx+1);
    }
    int check(const string& s, vector<int>& chk, size_t idx=0)
    {
        int nc=s[idx];
        if(max_len)
            chk[idx-1]=max(chk[idx-1], max_len);
        if(nc=='\0') return 0;
        if(this!=Aho::root and next.find(nc) == next.end())
            return failure->check(s, chk, idx);
        if(next.find(nc) != next.end())
            return next[nc]->check(s, chk, idx+1);
        return check(s, chk, idx+1);
    }
    // vector<string> find(const string& s, size_t idx=0) {}
    void get_failure()
    {
        root->failure=root;
        queue<Aho*> q;

        for(auto [c, n] : root->next)
            n->failure=root, q.push(n);
        while(q.size())
        {
            Aho* curr=q.front();
            q.pop();

            for(auto [c, n] : curr->next)
            {
                Aho* dest=curr->failure;
                while(dest != root and dest->next.find(c) == dest->next.end())
                    dest=dest->failure;
                if(dest->next.find(c) != dest->next.end())
                    dest=dest->next[c];
                n->failure=dest;

                n->max_len=max(n->failure->max_len, n->max_len);
                q.push(n);
            }
        }
    }
};
Aho* Aho::root=0;

int main(void)
{
#ifdef LOCAL
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    int m; cin >> m;
    vector<string> arr(m);
    for(int i=0; i<m; i++)
        cin >> arr[i];
    
    vector<int> chk(n);

    for(int i=0; i<(m+49)/50; i++)
    {
        Aho aho(1);
        for(int j=0; j<min(50, m-i*50); j++)
            aho.insert(arr[i*50+j]);
        aho.get_failure();
        aho.check(s, chk);
    }

    int remain=0, ans=n;
    for(int i=n-1; i>=0; i--)
    {
        remain=max(remain, chk[i]);
        if(remain) ans--, remain--;
    }
    cout << ans;
}

/*
    
*/