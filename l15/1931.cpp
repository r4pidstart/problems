#include<iostream>
#include<utility>
#include<algorithm>
int main(void)
{
    int n;
    scanf("%d", &n);
    std::pair <int, int> time[n];
    for(int i=0; i<n; i++)
        scanf("%d %d", &time[i].second, &time[i].first); // first : time of end
    sort(&time[0], &time[n]);

    int cur_time=0, count=0;
    for(int i=0; i<n; i++)
    {
        if(cur_time<=time[i].second)
        {
            cur_time=time[i].first;
            count++;
        }
    }
    printf("%d", count);
}
