# set: unordered, mutable, no duplicates
myset = {1,2,3}
print(myset)

myset = {1,2,3,1,2} # doesn't allow duplicates
print(myset)

myset = set([1,2,3]) # {1, 2, 3}
print(myset)

myset = set("hello") # {'o', 'e', 'h', 'l'}, order is arbitary
print(myset) # this can find how many unqiue character in the string

myset = set()
myset.add(1)
myset.add(2)
myset.add(3)
myset.add(4)
print(myset)
myset.remove(3)
print(myset)
# myset.remove(5) will raise a keyError

myset.discard(5) # remove an element from a set if it is a member
                 # if the element is not a member, do nothing

print(myset)

print(myset.pop()) # pop an arbitary member
print(myset)

for i in myset:
    print(i)

if 1 in myset:
    print("yes")
else:
    print("no")
