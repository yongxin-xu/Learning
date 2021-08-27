odds = {1,3,5,7,9}
evens = {0,2,4,6,8}
primes = {2,3,5,7}

u = odds.union(evens)
print(u)

i = odds.intersection(primes)
print(i)

emptyset = odds.intersection(evens)
print(emptyset)

setA = {1,2,3,4,5,6,7,8,9}
setB = {1,2,3,10,11,12}

diff = setA.difference(setB)
print(diff)

symdiff = setB.symmetric_difference(setA)
# the same as setA.symmetric_difference(setB)
print(symdiff)

setA.update(setB)
print(setA)

setA = {1,2,3,4,5,6,7,8,9}
setB = {1,2,3,10,11,12}
setA.intersection_update(setB)
print(setA)

setA = {1,2,3,4,5,6,7,8,9}
setB = {1,2,3,10,11,12}
setA.difference_update(setB)
print(setA)

setA = {1,2,3,4,5,6,7,8,9}
setB = {1,2,3,10,11,12}
setA.symmetric_difference_update(setB)
print(setB)

setA = {1, 2, 3, 4, 5, 6}
setB = {1, 2, 3}
print(setA.issubset(setB))
print(setB.issubset(setA))

print(setB.issuperset(setA))
print(setA.issuperset(setB))

setC = {4, 5, 6}
print(setA.isdisjoint(setB))
print(setA.isdisjoint(setC))
print(setB.isdisjoint(setC))

# copy set
setA_shallow_copy = setA
print(setA)
setA_shallow_copy.add(7)
print(setA)
print(setA_shallow_copy)

setA = {1,2,3,4,5,6}
setA_deep_copy = setA.copy()
print(setA)
setA_deep_copy.add(7)
print(setA)
print(setA_deep_copy)

# frozen set is a read-only set
a = frozenset([1,2,3,4,5,6])
print(a)
