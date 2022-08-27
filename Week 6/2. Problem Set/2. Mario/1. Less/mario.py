from cs50 import get_int


def get_height():
    while True:
        # while True is the closest think we have to a do while loop in python
        height = get_int("Height: ")
        if height > 0 and height < 9:
            break
    return height


def print_pyramid(height):

    j = height
    for i in range(height):
        # First loop will iterate from 0 to the height of the pyramid, responsible for each level
        for j in range(height - i - 1):
            # Height - i - 1, is the inversal value of hashes we print
            print(" ", end="")
        for k in range(i + 1):
            # i + 1 is the amount of hashed we have to print, since they always increase, we print for the value of i
            print('#', end="")
        print()


def main():
    height = get_height()
    print_pyramid(height)


if __name__ == "__main__":
    main()
