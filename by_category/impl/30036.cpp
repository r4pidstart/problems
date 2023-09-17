// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,t; scanf("%d%d", &n, &t);
    
    vector<pair<string, int> > arr;
    int assigned=0;
    for(int i=0; i<t; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        
        int target=-1;
        if(s2.back() == '%')
        {
            target=1L*(n-assigned)*stoi(s2.substr(0, s2.size()-1))/100;
        }
        else
        {
            target=min(n-assigned, stoi(s2));
        }

        int remain=target;
        for(int j=1; j<5; j++)
        {  
            int tmp=min(remain, (int)ceil(1.*target/4));
            remain-=tmp;
            arr.push_back({s1+to_string(j), tmp});
        }

        assigned+=target;
    }

#ifdef LOCAL
    printf("\n");
    for(auto [s, i] : arr)
        printf("%s %d\n", s.c_str(), i);
#endif

    if(n-assigned)
        return !printf("Invalid System");

    string target;
    cin >> target;

    if(isdigit(target.back()))
    {
        int prev=0;
        for(auto [s, i] : arr)
        {
            if(s == target)
            {
                if(i)
                    printf("%d %d\n", prev+1, prev+i);
                else
                    printf("Liar");
            }
            prev+=i;        
        }
    }
    else
    {
        int start=0, end=-1;
        for(auto [s, i] : arr)
        {
            if(s.substr(0, s.size()-1) == target)
            {
                if(end==-1)
                    end=start+i;
                else
                    end+=i;
            }
            if(end==-1)
                start+=i;
        }
        
        if(end!=start)
            printf("%d %d\n", start+1, end);
        else
            printf("Liar");
    }
}

/*
    
*/