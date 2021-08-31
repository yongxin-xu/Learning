# Strings: ordered, immutable, text representation
my_string = "Hello World"
print(my_string)

my_string_single_quote = 'Hello World'
print(my_string_single_quote)

my_string_sq_inside = "i\'m a programmer"
print(my_string_sq_inside)

my_string_multi_line = """Hello
World 3"""
print(my_string_multi_line)

my_string_cross_line = """Hello \
World 4"""
print(my_string_cross_line)

# indexing
char = my_string[1]
print(char)

# slicing
substring = my_string[1:5]
print(substring)

reversestring = my_string[::-1]
print(reversestring)

name = "Tom"
hello = "Hello"

sentence = hello + ', ' + name
print(sentence)

# iteration
for i in sentence:
    print(i)

# substr
if "ell" in hello:
    print("yes")
else:
    print("no")

my_string = '       Hello World    '
my_string_stripped = my_string.strip()
print(my_string)
print(my_string_stripped)
print(my_string_stripped.upper())
print(my_string_stripped.lower())
print(my_string_stripped.startswith("Hello"))
print(my_string_stripped.startswith("World"))
print(my_string_stripped.endswith("Hello"))
print(my_string_stripped.endswith("World"))
print(my_string_stripped.find('o'))
print(my_string_stripped.find('p'))
print(my_string_stripped.count('l'))

print(my_string_stripped.replace("World", "Universe"))
print(my_string_stripped.replace("Waorld", "Universe"))
