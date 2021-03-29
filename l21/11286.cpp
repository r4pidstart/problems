// https://www.acmicpc.net/problem/11286
// 2021-03-30 00:41:04 24ms
// 다음엔 좀 더 깔끔하게 쓰기
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

int append(int target, vector<int> &hip)
{
    int index=hip.size();
    hip.push_back(target);
    
    while(index>1)
    {
        if(abs(hip[index/2])==abs(hip[index]))
        {
            // 절대값이 같을 땐 작은 것
            if(hip[index/2]>hip[index])
            {
                swap(hip[index/2],hip[index]);
                index/=2;
            }
            else // hip[index/2]<=hip[index]
                return 0;

        }
        else if(abs(hip[index/2])>abs(hip[index]))
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
        if(index*2+1>size && abs(hip[index*2])<abs(hip[index]))
        // index*2+1이 없을 경우
        {
            swap(hip[index*2], hip[index]);
            index=index*2;
        }
        else if(index*2+1>size)
            if(abs(hip[index*2])==abs(hip[index]))
            {
                if(hip[index*2]<hip[index])
                {
                    swap(hip[index*2], hip[index]);
                    index=index*2;
                }
                else
                    return 0;
            }
            else
                return 0;
        else
        {
            if(abs(hip[index*2])==abs(hip[index*2+1]))
            {
                if(hip[index*2]<hip[index*2+1])
                {
                    if(abs(hip[index*2])==abs(hip[index]))
                    {
                        if(hip[index*2]<hip[index])
                        {
                            swap(hip[index*2], hip[index]);
                            index=index*2;
                        }
                        else
                            return 0;
                    }
                    else if(abs(hip[index*2])<abs(hip[index]))
                    {
                        swap(hip[index*2], hip[index]);
                        index=index*2;
                    }
                    else
                        return 0;
                }
                else // hip[index*2]>hip[index*2+1]
                {
                    if(abs(hip[index*2+1])==abs(hip[index]))
                    {
                        if(hip[index*2+1]<hip[index])
                        {
                            swap(hip[index*2+1], hip[index]);
                            index=index*2+1;
                        }
                        else
                            return 0;
                    }
                    else if(abs(hip[index*2+1])<abs(hip[index]))
                    {
                        swap(hip[index*2+1], hip[index]);
                        index=index*2+1;
                    }
                    else
                        return 0;
                }
            }
            else if(abs(hip[index*2])<abs(hip[index*2+1]))
            {
                if(abs(hip[index*2])==abs(hip[index]))
                {
                    if(hip[index*2]<hip[index])
                    {
                        swap(hip[index*2], hip[index]);
                        index=index*2;
                    }
                    else
                        return 0;
                }
                else if(abs(hip[index*2])<abs(hip[index]))
                {
                    swap(hip[index*2], hip[index]);
                    index=index*2;
                }
                else
                    return 0;
            }
            else
                if(abs(hip[index*2+1])==abs(hip[index]))
                {
                    if(hip[index*2+1]<hip[index])
                    {
                        swap(hip[index*2+1], hip[index]);
                        index=index*2+1;
                    }
                    else
                        return 0;
                }
                else if(abs(hip[index*2+1])<abs(hip[index]))
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