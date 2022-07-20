// https://www.acmicpc.net/problem/1062
// 2022-07-21 04:59:09 136ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,k; cin >> n >> k;
    k-=5; // a,n,t,i,c

    vector<string> arr(n);
    for(auto &it : arr)
    {
        cin >> it;
        it=it.substr(4, it.length()-8);
    }

    if(k < 0)
    {
        cout << 0;
        return 0;
    }

    int max_cnt=0;
    vector<int> permu(21);
    fill(permu.begin(), permu.begin()+k, 1);
    do
    {
        vector<int> alpha(26);
        alpha['a'-'a']=alpha['n'-'a']=alpha['t'-'a']=alpha['i'-'a']=alpha['c'-'a']=1;
        for(int i=0, idx=0; i<26; i++)
        {
            if(alpha[i]) continue;
            alpha[i]=permu[idx++]; 
        }

        int tmp_cnt=0;
        for(string &it : arr)
        {
            int flag=0;
            for(char &c : it)
                if(!alpha[c-'a']) flag++;
            if(!flag) tmp_cnt++;
        }
        max_cnt=max(max_cnt, tmp_cnt);
    } while (prev_permutation(permu.begin(), permu.end()));
    cout << max_cnt;
}

/*
    
*/