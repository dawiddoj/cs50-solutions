#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float ow;
    do
    {
        ow = get_float("Change owed: ");
        ow = round(ow * 100);
    }
    while (ow <= 0);
    int coins;
    do
    {
        coins = 0;
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
    while (ow > 0);
    printf("%i\n", coins);
}