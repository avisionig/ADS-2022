from collections import deque
def counter(x):
    st = deque()
    st.append(x)
    j = 1
    while(len(st) != x):
        st.appendleft(x - j)
        i = st[0]
        while (i > 0): 
            temp = st[len(st)-1]
            st.pop()
            st.appendleft(temp)
            i -= 1
        j += 1
    return st
list = []
for _ in range(int(input())):
    x = int(input())
    list.append(counter(x))
for i in list:
    while(len(i) != 0):
        print(i.popleft(),end=' ')
    print()