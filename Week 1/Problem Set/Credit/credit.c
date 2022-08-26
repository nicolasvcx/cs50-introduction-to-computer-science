#include <cs50.h>
#include <stdio.h>

long get_card_number(void);
int digits_counter(long credit_card_number);
int starting_digits(long credit_card_number);
int luhns_algorithm(long credit_card_number);

int main(void)
{
    long credit_card_number = get_card_number();
    int credit_card_length = digits_counter(credit_card_number);
    int first_digits = starting_digits(credit_card_number);
    int luhns = luhns_algorithm(credit_card_number);

    if (luhns % 10  == 0 && credit_card_length == 15 && (first_digits == 34 || first_digits == 37))
    {
        printf("AMEX\n");
        return 0;
    }
    if (luhns % 10  == 0 && credit_card_length == 16 && (first_digits == 51 || first_digits == 52 || first_digits == 53
            || first_digits == 54 || first_digits == 55))
    {
        printf("MASTERCARD\n");
        return 0;
    }
    if (luhns % 10  == 0 && (credit_card_length == 13 || credit_card_length == 16) && (int(first_digits) / 10 == 4))
    {
        printf("VISA\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }

}

long get_card_number(void)
{
    unsigned long credit_card_number = 0;
    do
    {
        credit_card_number = get_long("Number: "); // Prompt for card number repeatedly while it's equal to 0, since it's and unsigned long
    } // If we get past the max value, it will be set at 0 and prompt the user again
    while (credit_card_number == 0);

    return credit_card_number;

}
int digits_counter(long credit_card_number)
{
    int i = 0;
    while (credit_card_number > 0)
    {
        credit_card_number = credit_card_number / 10; // Divide the card number by 10 while it's bigger than 0
        i++; // Each time we divide it by 10 we take the last number out
    }

    return i;
}
int starting_digits(long credit_card_number)
{
    do
    {
        credit_card_number = credit_card_number / 10; // Divide the card number until it's smaller than 100
    }
    while (credit_card_number > 100);

    return credit_card_number;
}

int luhns_algorithm(long credit_card_number)
{
    int division_counter = 0;
    int odd_sum = 0;
    int even_sum = 0;

    while (credit_card_number > 0)
    {
        int last_digit = credit_card_number % 10;
        credit_card_number = credit_card_number / 10;
        division_counter++;

        if (division_counter % 2 != 0) // Every odd number will be added to this sum
        {
            odd_sum = odd_sum + last_digit;
        }
        if (division_counter % 2 == 0) // Every even number will be added to this sum
        {
            last_digit = last_digit * 2; // Multiply the last digit by 2

            if (last_digit <= 9) // if the number is smaller than 9 will immediately be added
            {
                even_sum = even_sum + last_digit;
            }
            if (last_digit > 9) // if it's bigger than 9 will be separated into 2 digits and added to each other
            {
                int first_digit = last_digit % 10;
                int second_digit = last_digit / 10;

                even_sum = even_sum + (first_digit + second_digit);
            }
        }
    }
    return odd_sum + even_sum;
}
