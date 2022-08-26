#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//index = 0.0588 * L - 0.296 * S - 15.8
int letter_counter(string text);
int word_counter(string text);
int sentence_counter(string text);

int main(void)
{
    string text = get_string("Text: ");
    // One variable to each function
    int letters = letter_counter(text);
    int words = word_counter(text);
    int sentences = sentence_counter(text);
    // Use casting to make the values letters, words, sentences into float number, so we don't lose any valu in the division
    float index = 0.0588 * ((float)letters / (float)words * 100) - 0.296 * ((float)sentences / (float)words * 100) - 15.8;
    // The round will round the floating point number to it's nearest integet
    if (round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    if (round(index) > 16)
    {
        printf("Grade 16+\n");
    }
    if (round(index) > 1 && round(index) < 16)
    {
        printf("Grade %.0f\n", round(index));
    }
}

int letter_counter(string text)
{
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            // Counts every time of word using the isalpha function
            letters++;
        }
    }
    return letters;
}
int word_counter(string text)
{
    int words = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            // Counts one word for every space
            words++;
        }
    }
    return words + 1;
    // Returns words + 1 because this loop won't count the last word, the last word wont have a space like the others
}
int sentence_counter(string text)
{
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            // Compare the letter if this three punctuations
            sentences++;
        }
    }
    return sentences;
}
