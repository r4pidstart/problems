// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m; scanf("%d%d", &n,&m);
        vector<pair<int,int> > arr(m);
        for(int i=0; i<m; i++) scanf("%d%d", &arr[i].first, &arr[i].second);

        sort(arr.begin(), arr.end());
        vector<int> book(n+1);
        
        for(int i=m-1; i>=0; i--)
        {
            for(int j=arr[i].second; j>=arr[i].first; j--)
                if(!book[j])
                {
                    book[j]=1;
                    break;
                }
        }
        printf("%d\n", accumulate(book.begin(), book.end(), 0));
    }
}

/*
    
*/