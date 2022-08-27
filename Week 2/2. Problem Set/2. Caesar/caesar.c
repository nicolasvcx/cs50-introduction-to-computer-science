#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main(int argc, string argv[])
{
    // argc is the argument counter, since we need 2 arguements
    // The first one is ./caesar (argv[0]) and the second is the key (argv[1])
    // Se if the amount of arguments is different than 2 we print the right usage
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // isalpha checks if the value is alphabetical
    // argv[1] is the key, so we iterate through the ith postition of the argv[1]
    // we get the lenght of the plaintext with the function strlen
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (isalpha(argv[1][i]) != 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }


    int key = atoi(argv[1]); // Turn the string into an int with atoi function
    string plaintext = get_string("Plaintext: ");

    printf("Ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isupper(plaintext[i]))
        {
            plaintext[i] = plaintext[i] - 65; // Subtract 65 wich is the numeric value for capital A in the
            plaintext[i] = (plaintext[i] + key) % 26; // ASCII chart, then we use the formula given
            printf("%c", plaintext[i] + 65); // And print with added 65, so we go back to the starting value
        }
        else if (islower(plaintext[i]))
        {
            plaintext[i] = plaintext[i] - 97; // Same as above but the lowercase a is 97
            plaintext[i] = (plaintext[i] + key) % 26;
            printf("%c", plaintext[i] + 97);
        }
        else
        {
            printf("%c", plaintext[i]); // For evverything that isn't a uppercase or lowercase letter we
            // print as it is
        }
    }
    printf("\n");
}