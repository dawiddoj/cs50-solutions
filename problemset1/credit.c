#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    long int ccnumber;
    int length;
    do
    {
        ccnumber = get_long("Number: ");
        length = floor(log10(labs(ccnumber))) + 1;
    }
    while(length<0);
    if (length==13 || length==15 || length==16)
    {
        int position = 0;
        int result = 0;
        int long numop = ccnumber;
        while (numop)
        {
            numop/=10;
            position=numop%10;
            result+=position*2;
            numop/=10;
        }
        int position2 = 0;
        int result2 = 0;
        int long numop2 = ccnumber;
        while (numop2)
        {
            position2=numop2%10;
            result2+=position2;
            numop2/=10;
            numop2/=10;
        }
        int check = result+result2;
        check%=10;
        int long numop3 = ccnumber;
        if (check==0)
        {
            if (length==13)
            {
                numop3/=1000000000000;
                if (numop3==4)
                {
                    printf("VISA\n");
                }
            }
            else if (length==15)
            {
                numop3/=10000000000000;
                if(numop3==34 || numop3==37)
                {
                    printf("AMEX\n");
                }
            }
            else if (length==16)
            {
                numop3/=100000000000000;
                if(numop3==51 || numop3==52 || numop3==53 || numop3==54 || numop3==55)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    numop3/=10;
                    if(numop3==4)
                    printf("VISA\n");
                }
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    
}