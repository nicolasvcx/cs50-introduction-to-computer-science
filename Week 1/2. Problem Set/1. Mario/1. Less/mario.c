#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 10;

    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8) ;
    // First loop will iterate through the height of the pyramid
    for (int i = 0; i < height; i++)
    {
        // Second loop will iterate through starting with the height - 1, decreasing it's value, until it's equal to 1
        for (int j = height - i; j > 1; j--)
        {
            printf(" ");
        }
        for (int k = i; k >= 0; k--)
        {
            // Third loop will print the hashes, wich will increase every time the first loop finishes
            printf("#");
        }
        // Will print a new line before the loops restart
        printf("\n");
    }
}