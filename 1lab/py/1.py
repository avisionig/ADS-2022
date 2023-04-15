list = [1,3,4,5,6]
i = 4
ans = [-1]
print(ans)
for j in range(i - 1, -1, -1):
    print(i)
    if list[j]<= list[i]:
        ans.append(list[j])
print(ans)