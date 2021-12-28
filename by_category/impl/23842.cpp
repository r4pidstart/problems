// https://www.acmicpc.net/problem/23842
// 2021-12-29 06:17:27 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> needed_matches({6,2,5,5,4,5,6,3,7,6,6});
    n-=4; // operator uses 4 matches

    for(int i=0; i<100; i++)
        for(int j=0; i+j<100; j++)
        {
            int used_matches=0;
            used_matches+=needed_matches[i/10];            
            used_matches+=needed_matches[i%10];            
            used_matches+=needed_matches[j/10];            
            used_matches+=needed_matches[j%10];
            used_matches+=needed_matches[(i+j)/10];       
            used_matches+=needed_matches[(i+j)%10];       
            if(used_matches == n) return !printf("%02d+%02d=%02d", i,j,i+j);  
        }
    printf("impossible");
}

/*
    
*/