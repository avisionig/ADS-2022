from collections import deque


list = deque()
output = [] 
exit = True
while (exit):
    a = input()
    b = a.split()
    if a == '!':
        exit = False
    elif len(b) == 2:
        if b[0] == '+':
            list.appendleft(int(b[1]))
        elif b[0] == '-':
            list.append(int(b[1]))
    elif a == '*' and len(list) >1 :
            output.append(list.popleft() + list.pop())
    elif a =='*' and len(list) == 1: 
            output.append(list.pop() * 2)
    elif len(list) == 0:
            output.append('error')
    else:
        pass
for i in output:
    print(i)
