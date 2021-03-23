
#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
    while(1)
    {
        int n; scanf("%d", &n);
        if(n==0) break;
        vector <int> arr(n);
        long long max=0, prev=0, sequence=0;
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);

        for(int i=0; i<n; i++)
        {
            if(prev<arr[i])
            {
                sequence=0;
                for(int j=i; j<n; j++) // 앞으로
                {
                    if(arr[i]>arr[j])
                        break;
                    sequence++;
                }
                for(int j=i-1; j>=0; j--) // 뒤로
                {
                    if(arr[i]>arr[j])
                        break;
                    sequence++;
                }
                if(max<sequence*arr[i])
                    max=sequence*arr[i];
            }
            else
            prev=arr[i];
        }

        printf("%lld\n", max);
    }
}