import sys
import timeit
myList = [0, 1, 2, "hello", True]
myTuple = (0, 1, 2, "hello", True)

# size of a list is larger than a tuple
print(sys.getsizeof(myList), "bytes")
print(sys.getsizeof(myTuple), "bytes")

# it takes less time to create a tuple than a list
print(timeit.timeit(stmt="[0,1,2,3,4,5]", number=10000000))
print(timeit.timeit(stmt="(0,1,2,3,4,5)", number=10000000))
