n = int(input())
m = int(input())
d = list(map(int, input().split()))
c = list(map(int, input().split()))

distance_sum = [0] * 100005
city = [(0,0)] * 100005

for i in range(n+1):
    distance_sum[i+1] = distance_sum[i] + d[i]
for i in range(n):
    city[i] = (distance_sum[i+1]-distance_sum[i], c[i])

total = 0
cidx = 0
fuel_rem = m - city[0][0]

while cidx < n:
    # find optimal city
    opt_dist = 0
    opt_idx = -1
    for i in range(cidx+1, n):
        opt_dist = opt_dist + city[i][0]
        if opt_dist > m:
            break
        if city[cidx][1] > city[i][1]:
            opt_idx = i
            break
    
    # check the distance to the end
    end_dist = distance_sum[n+1] - distance_sum[cidx+1]
    if opt_idx == -1 and end_dist < m:
        opt_idx = n
        opt_dist = end_dist
    
    # optimal city exist
    if opt_idx > 0:
        pay = max(0, opt_dist - fuel_rem) * city[cidx][1]
        total = total + pay
        fuel_rem = max(fuel_rem, opt_dist)
        cidx = opt_idx
        fuel_rem = fuel_rem - opt_dist
        continue
    
    # optimal city not exist
    pay = (m - fuel_rem) * city[cidx][1]
    total = total + pay
    fuel_rem = m
    cidx = cidx + 1
    fuel_rem = fuel_rem - city[cidx][0]

print(total)

# 20분 57초 15
