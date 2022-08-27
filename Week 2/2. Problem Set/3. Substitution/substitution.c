#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Checks if the amount of arguments is 2
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Checks if the second arguments has 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // Checks if all arguments are letters
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key must contain only alphabetical characters\n");
            return 1;
        }
    }
    int repetition = 0;
    // Checks if it has repeated letters
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                repetition++;
            }
        }
    }
    //
    if (repetition != 26)
    {
        printf("You shouldn't repeat letters\n");
        return 1;
    }



    string plaintext = get_string("Plaintext: ");
    string cipher = argv[1];

    printf("ciphertext: ");

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isupper(plaintext[i]))
        {
            // Create a bariable called key and make it's value the number of the letter in plaintext[i]
            // Minus the equivalent of A in capital letters
            int key = (int)plaintext[i] - 65;
            // This will give us a number that is the same as it's position on the alphabet
            // The variable cipher has the alphabetic order we supposed to change
            plaintext[i] = cipher[key];
            printf("%c", toupper(plaintext[i]));
        }
        else if (islower(plaintext[i]))
        {
            int key = (int)plaintext[i] - 97;
            plaintext[i] = cipher[key];
            printf("%c", tolower(plaintext[i]));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}