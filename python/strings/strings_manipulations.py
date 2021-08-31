my_string = "how are you doing"
my_list = my_string.split() # default delimiter is space
print(my_list) # ['how', 'are', 'you', 'doing']

my_string2 = "how,are,you,doing"
my_list2 = my_string2.split()
print(my_list2)
my_list3 = my_string2.split(",")
print(my_list3)

new_string = ''.join(my_list)
print(new_string)

my_list = ['a'] * 6000000

from timeit import default_timer as timer

# bad 
start = timer()
my_string = ''
for i in my_list:
    my_string += i
stop = timer()
print(stop - start)

# good
start = timer()
my_string = ''.join(my_list)
stop = timer()
print(stop - start)

