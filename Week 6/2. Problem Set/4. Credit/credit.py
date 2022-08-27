from cs50 import get_int
# In order for this to work we have to do casting in a bunch of variables
# Since python don't let you choose the datatype beforehand
# Besides this, it's basically the same thing we did in Week 1
# Just using the Python semantic


def main():
    credit_card_number = get_credit_card_number()
    amount_of_digits = get_amount_of_digits(credit_card_number)
    starting_digits = int(get_starting_digits(credit_card_number))
    luhns = int(luhns_algorithm(credit_card_number))
    first_digit = starting_digits / 10
    first_digit = int(first_digit)

    if (luhns % 10 == 0 and amount_of_digits == 16 and (starting_digits == 51 or starting_digits == 52 or starting_digits == 53 or starting_digits == 54 or starting_digits == 55)):
        print("MASTERCARD")
    elif (luhns % 10 == 0 and amount_of_digits == 15 and (starting_digits == 34 or starting_digits == 37)):
        print("AMEX")
    elif (luhns % 10 == 0 and (amount_of_digits == 13 or amount_of_digits == 16) and (first_digit == 4)):
        print("VISA")
    else:
        print("INVALID")


def get_credit_card_number():
    while True:
        credit_card_number = get_int("Number: ")
        if credit_card_number > 100:
            break
    return credit_card_number


def get_amount_of_digits(credit_card_number):

    i = -1
    while credit_card_number > 0:
        credit_card_number = int(credit_card_number) / 10
        i += 1

    return i


def get_starting_digits(credit_card_number):

    while credit_card_number > 100:
        credit_card_number = int(credit_card_number) / 10

    return credit_card_number


def luhns_algorithm(credit_card_number):

    division_counter = 0
    odd_sum = 0
    even_sum = 0

    while (credit_card_number > 0):
        last_digit = int(credit_card_number) % 10
        credit_card_number = int(credit_card_number) / 10
        credit_card_number = int(credit_card_number)
        division_counter += 1

        if (division_counter % 2 != 0):
            # Every odd number will be added to this sum
            odd_sum = odd_sum + last_digit

        if (division_counter % 2 == 0):
            # Every even number will be added to this sum
            last_digit = last_digit * 2
            # Multiply the last digit by 2

            if (last_digit <= 9):
                # if the number is smaller than 9 will immediately be added
                even_sum = even_sum + last_digit

            if (last_digit > 9):
                # if it's bigger than 9 will be separated into 2 digits and added to each other
                first_digit = last_digit % 10
                second_digit = last_digit / 10

                even_sum = even_sum + (int(first_digit) + int(second_digit))

    return odd_sum + even_sum


if __name__ == "__main__":
    main()