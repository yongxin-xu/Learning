# Dictionary: Key-Value pairs, Unordered, Mutable
mydict = {"name": "Max", "age": 28, "city": "Boston"}
print(mydict)

mydict2 = dict(name="Alex", age=27, city="Chicago")
print(mydict2)

value = mydict["name"]
print(value)
# kerror = mydict["sex"] # will return keyError

# if key exists, update the value, otherwise insert the k,v pair
mydict["email"] = "max@xyz.com"
print(mydict)
mydict["name"] = "Max2"
print(mydict)

# delete k,v
del mydict["name"]
print(mydict)

# or use pop
mydict.pop("age")
print(mydict)

mydict = {"name": "Max", "age": 28, "city": "Boston"}
# test if a name exists in the kv
if "name" in mydict:
    print(mydict["name"])

try:
    print(mydict["sex"])
except:
    print("There is no key named 'sex' in the dictionary")

for key in mydict: # or for key in mydict.keys()
    print(key)

for k, v in mydict.items():
    print(k, ":", v)

# perform a deep copy, or use mydict_copy = dict(mydict)
mydict_copy = mydict.copy()
mydict_copy["copy"] = True
print(mydict)
print(mydict_copy)

# merge two dictionaries
mydict_1 = {"name": "Max", "age": 28, "email": "max@xyz.com"}
mydict_2 = dict(name="Mary", age=27, city="Boston")

mydict_1.update(mydict_2)
print(mydict_1)
