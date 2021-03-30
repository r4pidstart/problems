// https://www.acmicpc.net/problem/1927
// 2021-03-29 00:50:08 24ms
#include<iostream>
#include<vector>
using namespace std;

int append(int target, vector<int> &heap)
{
    int index=heap.size();
    heap.push_back(target);
    
    while(index>1)
    {
        if(heap[index/2]<heap[index])
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
    printf("%d\n", -1*heap[1]);
    heap[1]=heap[heap.size()-1];
    heap.pop_back();

    int size=heap.size()-1, index=1;
    while(index*2<=size)
    {
        if(index*2+1>size && heap[index*2]>heap[index])
        // index*2+1이 없을 경우
        {
            swap(heap[index*2], heap[index]);
            index=index*2;
        }
        else if(index*2+1>size)
            return 0;
        else
        {
            if(heap[index*2]>heap[index*2+1])
            {
                if(heap[index*2]>heap[index])
                {
                    swap(heap[index*2], heap[index]);
                    index=index*2;
                }
                else
                    return 0;
            }
            else
                if(heap[index*2+1]>heap[index])
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
            append(-1*tmp, heap);
    }
    return 0;
}

