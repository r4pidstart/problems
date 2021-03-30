// https://www.acmicpc.net/problem/11286
// 2021-03-30 00:41:04 24ms
// 다음엔 좀 더 깔끔하게 쓰기
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

int append(int target, vector<int> &heap)
{
    int index=heap.size();
    heap.push_back(target);
    
    while(index>1)
    {
        if(abs(heap[index/2])==abs(heap[index]))
        {
            // 절대값이 같을 땐 작은 것
            if(heap[index/2]>heap[index])
            {
                swap(heap[index/2],heap[index]);
                index/=2;
            }
            else // heap[index/2]<=heap[index]
                return 0;

        }
        else if(abs(heap[index/2])>abs(heap[index]))
        {
            swap(heap[index/2],heap[index]);
            index/=2;
        }
        else
            return 0;
    }
    return 0;
}

int print_and_remove(vector<int> &heap)
{
    printf("%d\n", heap[1]);
    heap[1]=heap[heap.size()-1];
    heap.pop_back();

    int size=heap.size()-1, index=1;
    while(index*2<=size)
    {
        if(index*2+1>size && abs(heap[index*2])<abs(heap[index]))
        // index*2+1이 없을 경우
        {
            swap(heap[index*2], heap[index]);
            index=index*2;
        }
        else if(index*2+1>size)
            if(abs(heap[index*2])==abs(heap[index]))
            {
                if(heap[index*2]<heap[index])
                {
                    swap(heap[index*2], heap[index]);
                    index=index*2;
                }
                else
                    return 0;
            }
            else
                return 0;
        else
        {
            if(abs(heap[index*2])==abs(heap[index*2+1]))
            {
                if(heap[index*2]<heap[index*2+1])
                {
                    if(abs(heap[index*2])==abs(heap[index]))
                    {
                        if(heap[index*2]<heap[index])
                        {
                            swap(heap[index*2], heap[index]);
                            index=index*2;
                        }
                        else
                            return 0;
                    }
                    else if(abs(heap[index*2])<abs(heap[index]))
                    {
                        swap(heap[index*2], heap[index]);
                        index=index*2;
                    }
                    else
                        return 0;
                }
                else // heap[index*2]>heap[index*2+1]
                {
                    if(abs(heap[index*2+1])==abs(heap[index]))
                    {
                        if(heap[index*2+1]<heap[index])
                        {
                            swap(heap[index*2+1], heap[index]);
                            index=index*2+1;
                        }
                        else
                            return 0;
                    }
                    else if(abs(heap[index*2+1])<abs(heap[index]))
                    {
                        swap(heap[index*2+1], heap[index]);
                        index=index*2+1;
                    }
                    else
                        return 0;
                }
            }
            else if(abs(heap[index*2])<abs(heap[index*2+1]))
            {
                if(abs(heap[index*2])==abs(heap[index]))
                {
                    if(heap[index*2]<heap[index])
                    {
                        swap(heap[index*2], heap[index]);
                        index=index*2;
                    }
                    else
                        return 0;
                }
                else if(abs(heap[index*2])<abs(heap[index]))
                {
                    swap(heap[index*2], heap[index]);
                    index=index*2;
                }
                else
                    return 0;
            }
            else
                if(abs(heap[index*2+1])==abs(heap[index]))
                {
                    if(heap[index*2+1]<heap[index])
                    {
                        swap(heap[index*2+1], heap[index]);
                        index=index*2+1;
                    }
                    else
                        return 0;
                }
                else if(abs(heap[index*2+1])<abs(heap[index]))
                {
                    swap(heap[index*2+1], heap[index]);
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
    vector<int> heap(1,0);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &tmp);
        if(tmp==0)
            if(heap.size()==1)
                printf("0\n");
            else
                print_and_remove(heap);
        else
            append(tmp, heap);
    }
    return 0;
}