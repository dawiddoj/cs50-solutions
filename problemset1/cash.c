#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    /* take float from user */
    float ow;
    do
    {
        ow = get_float("Change owed: ");
        ow = round(ow * 100);
    }
    /* make sure that input is greater than 0 */
    while (ow <= 0);
    /* setting up counter for amount of coins that were used */
    int coins;
    do
    {
        coins = 0;
        /* while loops checking if you can still use greater coin,
        inside loops it updates coins counter */
        while (ow >= 25)
        {
            ow -= 25;
            coins++;
        }
        while (ow >= 10)
        {
            ow -= 10;
            coins++;
        }
        while (ow >= 5)
        {
            ow -= 5;
            coins++;
        }
        while (ow >= 1)
        {
            ow -= 1;
            coins++;
        }
    }
    /* does it until cash=0 */
    while (ow > 0);
    /* prints the amount of coins used */
    printf("%i\n", coins);
}