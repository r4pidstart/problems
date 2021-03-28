// https://www.acmicpc.net/problem/11279
// 2021-03-29 00:48:01 20ms
#include<iostream>
#include<vector>
using namespace std;

int append(int target, vector<int> &hip)
{
    int index=hip.size();
    hip.push_back(target);
    
    while(index>1)
    {
        if(hip[index/2]<hip[index])
        {
            swap(hip[index/2],hip[index]);
            index/=2;
        }
        else
            return 0;
    }
    return 0;
}

int print_and_remove(vector<int> &hip)
{
    printf("%d\n", hip[1]);
    hip[1]=hip[hip.size()-1];
    hip.pop_back();

    int size=hip.size()-1, index=1;
    while(index*2<=size)
    {
        if(index*2+1>size && hip[index*2]>hip[index])
        // index*2+1이 없을 경우
        {
            swap(hip[index*2], hip[index]);
            index=index*2;
        }
        else if(index*2+1>size)
            return 0;
        else
        {
            if(hip[index*2]>hip[index*2+1])
            {
                if(hip[index*2]>hip[index])
                {
                    swap(hip[index*2], hip[index]);
                    index=index*2;
                }
                else
                    return 0;
            }
            else
                if(hip[index*2+1]>hip[index])
                {
                    swap(hip[index*2+1], hip[index]);
                    index=index*2+1;
                }
                else
                    return 0;
        }
    }
    return 0;
}

int main(void)
{
    int n, tmp; scanf("%d", &n);
    vector<int> hip(1,0);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &tmp);
        if(tmp==0)
            if(hip.size()==1)
                printf("0\n");
            else
                print_and_remove(hip);
        else
            append(tmp, hip);
    }
    return 0;
}

