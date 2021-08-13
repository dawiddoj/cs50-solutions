#include <stdio.h>
#include <cs50.h>

/* program printing tower from mario */

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    if (n == 1)
    {
        printf("#\n");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            int j = 0;
            while (j < n - i)
            {
                printf(" ");
                j++;
            }
            for (int x = 1; x <= i; x++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
}