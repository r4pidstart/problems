n,k=map(int, input().split())
arr=list(map(int, input().split()))

sum_arr=sum(arr)
mina=maxa=k * sum_arr - arr[0]

for i in range(n):
    mina=min(mina, k*sum_arr - arr[i])
    maxa=max(maxa, k*sum_arr - arr[i])

print(maxa-mina)
