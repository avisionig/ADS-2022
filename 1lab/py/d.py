str = input()
list = []
map = {}
for i in str:
    if i in list:
        temp = str.index(i)
        if len(list) > 0 and str[temp] == list[len(list) - 1]:
            list.pop()
    else:
        list.append(i)
for i in str:
    if i not in map:
        map[i] = 1
    else: 
        map[i] += 1
for i in map:
    if map[i] % 2 != 0:
        print("NO")
        exit()
if len(list)==0:
    print("YES")
else:
    print("NO")