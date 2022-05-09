import math

n=100000
arr = [True for i in range(n+1)]

for i in range(2, int(math.sqrt(n)) + 1) :
  if arr[i] == True :
    j = 2
    while i * j <= n :
      arr[i * j] = False
      j += 1

primes=[]
for i in range(2, n+1):
  if arr[i]:
      primes.append(i);
  
target=int(input())
ans=0
for i in range(len(primes)):
  for j in range(i):
    if(primes[i]**3 * primes[j] <= target):
      ans+=1
    else:
      break
  
print(ans)