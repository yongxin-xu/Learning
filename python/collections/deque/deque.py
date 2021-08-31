from collections import deque

# double linked list
d = deque()

d.append(1)
d.append(2)
d.append(3)
print(d)

d.appendleft(5)
print(d)

d.pop()
print(d)

d.popleft()
print(d)

d.insert(1, 5)
print(d)

d.extend([1,2,3,4,5])
print(d)

d.clear()
