
while True:
    height = int(input("Height: "))
    if height < 9 and height > 0:
        break

for i in range(height):

    # print left middle-aligned triangle
    for j in range(height):
        if j > 


        print(" ", end = "")

    for k in range(i):
        print("#", end = "")

    # print space between the two triangles
    print(" ", end = "")

    # print right middle-aligned triangle
    for l in range(i):
        print("#", end = "")

    # return prompt to new line after each row is completed
    print()


