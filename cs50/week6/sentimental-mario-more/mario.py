
while True:
    height = int(input("Height: "))
    if height < 9 and height > 0:
        break

for i in range(height):

    # print left middle-aligned triangle
    for j in range(height):

        # start printing # after correct number of spaces
        if j > (height - i):
            print("#", end = "")
        else:
            print(" ", end = "")

        # print space and then right middle-aligned triangle
        if j == height:
            print(" ", "#" * i, end = "")

    # return prompt to new line after each row is completed
    print()


