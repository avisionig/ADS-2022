str = input().split()
def equalStr(str):
    list = []
    for i in str:
        if i != "#":
            list.append(i)
        else:
            if len(list):
                list.pop()
    return "".join(list)
 
if equalStr(str[0]) == equalStr(str[1]):
    print('Yes')
else:
    print('No')