#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* program that is encrypting messages using caesar cipher */

string cypher(char text[], int key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int length = strlen(argv[1]);
        int control = 0;
        int check = 0;
        for (int i = 0; i < length; i++)
        {
            check = isdigit(argv[1][i]);
            if (check == 2048)
            {
                control++;
            }
        }
        if (length == control)
        {
            int key = atoi(argv[1]);
            char plaintext[100];
            string copy = get_string("plaintext: ");
            strcpy(plaintext, copy); 
            printf("ciphertext: %s\n", cypher(plaintext, key));
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

string cypher(char text[], int key)
{
    char ch;
    for (int i = 0; text[i] != '\0'; i++)
    {
        ch = text[i];
        if (islower(ch))
        {
            ch = ((text[i] - 'a') + key) % 26 + 'a';
            text[i] = ch;
        }
        else if (isupper(ch))
        {
            ch = ((text[i] - 'A') + key) % 26 + 'A';
            text[i] = ch;
        }
    }
    return text;
}