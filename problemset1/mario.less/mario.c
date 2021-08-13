#include <stdio.h>
#include <cs50.h>

/* program printing tower from mario */

int main(void)
{
    /* while loop that gets height integrer between 1-8 from user rejecting other inputs */
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    /* work around for valid input for height = 1 */
    if (n == 1)
    {
        printf("#\n");
    }
    /* rest of code printing the tower */
    else
    {
        for (int i = 1; i <= n; i++)
        {
            /* first loop takes height and compares it with counter i, 
            if i is less than n it goes forward with code */
            int j = 0;
            /* while loop that prints spaces to align the hashes properly, 
            it gets the amount of spaces by comparing counter j to height
            minus counter i from previous for loop, it leaves right amount
            of space for hashes */
            while (j < n - i)
            {
                printf(" ");
                j++;
            }
            /* for loop that prints the right amount of hashes based on the
            counter i */
            for (int x = 1; x <= i; x++)
            {
                printf("#");
            }
            /* after printing right amount of spaces and hashes, it moves
            to another line of tower, updates counter i so other loops
            know what amount of signs it has to print*/
            printf("\n");
        }
    }
}