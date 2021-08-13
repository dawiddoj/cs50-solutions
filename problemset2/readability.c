#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

/* program calculating coleman-liau index */

const int zero = 0;

int main(void)
{
    string text[1];
    text[zero] = get_string("Text: ");
    /* string length */
    int length = strlen(text[zero]);
    /* calculating amount of letters, words and sentences in text */
    int words = zero;
    for (int i = zero; i < length; i++)
    {
        if (text[zero][i] == ' ')
        {
            words++;
        }
    }
    /* because of the way that i am obtaining amount of words i have to add one manually */
    words++;
    int sentences = zero;
    for (int i = zero; i < length; i++)
    {
        if (text[zero][i] == '.' || text[zero][i] == '!' || text[zero][i] == '?')
        {
            sentences++;
        }
    }
    int letters = zero;
    for (int i = zero; i < length; i++)
    {
        if ((text[zero][i] >= 'a' && text[zero][i] <= 'z') || (text[zero][i] >= 'A' && text[zero][i] <= 'Z'))
        {
            letters++;
        }
    }
    /* calculating index */
    int index = round(((0.0588 * ((float)letters / (float)words * 100)) - (0.296 * ((float)sentences / (float)words * 100))) - 15.8);
    /* printing right output */
    if (index <= 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}