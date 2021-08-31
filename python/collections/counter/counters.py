from collections import Counter

a = "aaaaaaaaaaabbbbbbbcccc"

my_counter = Counter(a)
print(my_counter) # Counter({'a': 11, 'b': 7, 'c': 4})
print(my_counter.values()) # dict_values([11, 7, 4])
print(my_counter.most_common(2))
print(list(my_counter.elements()))

