
while True:
    height = int(input("Height: "))

    if height > 0 and height < 9:
        break

# initialise counter
i = 0
j = i + 1
k = 0
l = 0

for i in range(height):

    # print left middle-aligned triangle
    for j in range(height):
        print(" ", end = "")

    for k in range(k <= i):
        print("#", end = "")

    # print space between the two triangles
    print(" ", end = "")

    # print right middle-aligned triangle
    for l in range(l <= i):
        print("#", end = "")

    # return prompt to new line after each row is completed
    print()


