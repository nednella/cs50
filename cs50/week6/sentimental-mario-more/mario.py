
while True:

    try:
        height = int(input("Height: "))
    except ValueError:
        continue
    else:
        if height < 9 and height > 0:
            break



for i in range(height):

    # print left middle-aligned triangle
    for j in range(height + i + 3):

        # start printing # after correct number of spaces
        if (j == height or j == height + 1 or i + j < height - 1):
            print(" ", end = "")
        else:
            print("#", end = "")

    # return prompt to new line after each row is completed
    print()
