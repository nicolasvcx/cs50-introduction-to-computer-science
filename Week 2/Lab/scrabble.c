#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int points = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            // Uppercase letters in the ASCII chart starts at 65
            points = points + POINTS[(word[i] - 65)];
        }
        else if (islower(word[i]))
        {
            // Lowercase letters in the ASCII chart start at 97
            points = points + POINTS[(word[i] - 97)];
            // POINTS if the Global Array with the points for each letter
            // Each position is it's numerical equivalent to a letter
            // So we get the ASCII value of the letter with the word[i]
            // and remove the number related to the letter in the ASCII chart
        }
    }
    return points;
}
