import random

a = random.random() # a random float number from 0 to 1
print(a)

b = random.uniform(1, 10) # a random float number from 1 to 10
print(b)

c = random.randint(1, 10) # a random integer number from 1 to 10
print(c)

d = random.normalvariate(0, 1) # gauss distribution
print(d)

mylist = list("ABCDEFGHI")
f = random.choice(mylist)
print(f)
g = random.sample(mylist, 3) # unique 3 choices
print(g)
h = random.choices(mylist, k=3) # can pick single element multiple times
print(h)
random.shuffle(mylist) # shuffle elements in-place
print(mylist)

# psudo random, can be reproducible if setting the same seed
random.seed(1)
print(random.random())
print(random.random())
print(random.random())
