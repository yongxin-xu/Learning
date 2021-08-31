# %, .format() f-String (since 3.6)
var = "Tom"
age = 17
my_string = "the variable is %s with age %d" % (var, age)
print(my_string)

my_string = "the variable is {} with age {}".format(var, age)
print(my_string)

# python 3.6 or newwer
my_string = f"the variable is {var} with age {age}"
print(my_string)
