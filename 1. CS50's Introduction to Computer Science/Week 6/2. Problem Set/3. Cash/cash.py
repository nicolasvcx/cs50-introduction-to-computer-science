from cs50 import get_float
# Python wont work the same way as the version in C
# The C version is overly complicateed anyway


def get_cents():
    while True:
        cents = get_float("Change Owed: ")
        if cents > 0:
            break
    return int(cents * 100)
    # returns the value times 100 so we can work with and int value


def main():
    cents = get_cents()
    count = 0
    while cents > 0:
        # pretty straightforward we keep taking the value of the coin and adding 1 to the count
        if cents >= 25:
            cents = cents - 25
            count += 1
        elif cents >= 10:
            cents = cents - 10
            count += 1
        elif cents >= 5:
            cents = cents - 5
            count += 1
        elif cents >= 1:
            cents = cents - 1
            count += 1

    print(count)


if __name__ == "__main__":
    main()