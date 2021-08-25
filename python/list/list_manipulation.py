mylist = ["banana", "cherry", "apple"]
print(mylist)

print(mylist[0]) # the first element, 'banana'
print(mylist[1]) # the second element, 'cherry'
# print(mylist[3]) # index out of range ERROR 
print(mylist[-1]) # the last element, 'apple'

# iteration
print("iteration")
for item in mylist:
    print(item)

# test if an item is in a list
if "banana" in mylist:
    print("banana is in the list")
else:
    print("banana is not in the list")
if "lemon" in mylist:
    print("lemon is in the list")
else:
    print("lemon is not in the list")

# the length of the list
print("There are", len(mylist), "elements in the list")

# append element
print("The original list is", mylist)
mylist.append("lemon")
print("After appending, the new lists is", mylist)

# insert into a specific position
print("The original list is", mylist)
mylist.insert(1, "strawberry")
print("After the insertion, the new lists is", mylist)

# pop() returns the last element, and pop it out
print("The original list is", mylist)
el = mylist.pop()
print("After pop(", el, ")\nthe new lists is", mylist)


# remove specific element
mylist.remove("cherry")
# mylist.remove("carrot") will return valueError
mylist.clear() # clear all elements in the list
print("\n\nAfter clearing all elements, the list is", mylist)

# mylist.reverse()  reverse the list
# mylist.sort()     sort the list
mylist2 = [3, 1, 4, 1, 5, 9, 2, 6]
mylist2.reverse()
print(mylist2)
mylist2.sort()
print(mylist2)

# non-inplace sort
print("\n\n\n")
mylist3 = [3, 1, 4, 1, 5, 9, 2, 6]
sortedList3 = sorted(mylist3)
print("mylist3", mylist3)
print("sorted mylist3", sortedList3)

repeatedList = [4] * 5
print(repeatedList)
newList = repeatedList + mylist3
print(newList)

# slice
mylist4 = [1, 2, 3, 4, 5, 6, 7, 8, 9]
a = mylist4[1:5]
print(a)

b = mylist4[::1]
print(b) # every item
c = mylist4[::2]
print(c) # every second item

# copy is a shallow copy
list_org = ["banana", "cherry", "apple"]
list_shallow_copy = list_org

list_shallow_copy.append("lemon")

print(list_org)
print(list_shallow_copy)

list_org2 = ["banana", "cherry", "apple"]
list_deep_copy = list_org2.copy()
list_deep_copy.append("lemon")
print(list_org2)
print(list_deep_copy)

mylist5 = [1, 2, 3, 4, 5, 6]
e = [i*i for i in mylist5]
print(e)
