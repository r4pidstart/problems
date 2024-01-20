// https://www.acmicpc.net/problem/30917
// 2024-01-20 22:50:11
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    vector<int> A(10000), B(10000);
    int a=-1, b=-1;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dist(1, 10000);

    setbuf(stdout, nullptr);
    while(true)
    {
        int target=-1;
        if(a==-1)
        {
            do
            {
                target=dist(gen);
            } while (A[target]);
            
            printf("? A %d\n", target);
            int ret; scanf("%d", &ret);
            if(ret==1) a=target;
            else A[target]=1;
        }
        else if(b==-1)
        {
            do
            {
                target=dist(gen);
            } while (B[target]);
            
            printf("? B %d\n", target);
            int ret; scanf("%d", &ret);
            if(ret==1) b=target;
            else B[target]=1;
        }
        else
            break;
    }

    assert(a!=-1 and b!=-1);
    printf("! %d", a+b);
}

/*
    
*/