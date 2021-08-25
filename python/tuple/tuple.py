# Tuple: ordered, immutable, allows duplicate elments
# cannot be modified after creation
# Initialize a tuple
mytuple = ("Max", 28, "Boston")
print(mytuple)
mytuple = "Max", 25, "Boston" # parenthses is optional
print(mytuple)
mytuple = tuple(["Max", 24, "Boston"])
print(mytuple)

# get items
item_first = mytuple[0]
print(item_first)

# assign a tuple element like:
# mytuple[1] = 29 # will get a type error
for item in mytuple:
    print(item)

# test if something is in the tuple
if "Max" in mytuple:
    print("yes")
else:
    print("no")

mytuple = ('a','p','p','l','e')
# get the length
print("length of the tuple is", len(mytuple))
# print the count of some element
print("count of 'p' in the tuple is", mytuple.count('p'))
print("count of 'f' in the tuple is", mytuple.count('f'))

print(mytuple.index('e'))
print(mytuple.index('p')) # return the first index of 'p'
# print(mytuple.index('f')) # will return a valueError

# list <=> tuple
mylist = list(mytuple)
print(mylist)
mytuple2 = tuple(mylist)
print(mytuple2)

# slicing
a = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
b = a[5:7]
print(b)

c = a[-3:-1]
print(c)

r = a[::-1]
print(r) # reverse a tuple

mytuple = "Max", 28, "Boston"
name, age, city = mytuple
print("Name:", name, "Age:", age, "City:", city)

mytuple = (0, 1, 2, 3, 4)
i1, *i2, i3 = mytuple
print(i1) # the first element
print(i3) # the last element
print(i2) # [1,2,3] as a LIST

# tuple can be more efficient since it is immutable
