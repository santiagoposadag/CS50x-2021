height = input("Height: ")

while height.isalpha() or height == "":
    height = input("Height: ")

height = int(height)

while height < 1 or height > 8:
    height = int(input("Height: "))

whites = height - 1
hashes = 1

for i in range(height):
    for j in range(1):
        print((whites * " ") + (hashes * "#") + "  " + (hashes * "#"))
        whites -= 1
        hashes += 1