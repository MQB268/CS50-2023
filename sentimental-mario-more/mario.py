# TODO
height = 0
while height < 1 or height > 8:
    try:
        height = int(input("Height: "))
    except ValueError:
        print("Not an integer")
center_space = "  "
for i in range(height):
    space = ""
    tag = ""
    for j in range(height - i - 1):
        space += " "
    for k in range(i + 1):
        tag += "#"
    text = space + tag + center_space + tag
    print(text)
