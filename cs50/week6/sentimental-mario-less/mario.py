
while True:

    try:
        height = int(input("Height: "))
    except ValueError:
        continue
    else:
        if height < 9 and height > 0:
            break

for i in range(height):

    for j in range(height + 1):

        if j == height:
            print("#", end = "")
        else:
            print(" ", end = "")
            
    print()
