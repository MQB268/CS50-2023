#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask user to input card number
    long _default1 = 1000000000000;
    long _default2 = 1000000000000000;
    long number;

    do
    {
        number = get_long("Number: ");
    }
    while (!number || number < 0);

    long _number = number;

    // Check sum
    int position = 0;
    int total = 0;

    while (number)
    {
        position++;

        if (position % 2 == 0)
        {
            int mod = number % 10;

            if (mod * 2 / 10 > 0)
            {
                total += ((mod * 2 / 10) + (mod * 2 % 10));
            }
            else
            {
                total += (number % 10) * 2;
            }
        }
        else
        {
            total += number % 10;
        }
        number /= 10;
    }

    if (position < 13 || position > 16 || total % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        long _count = 1;

        for (int j = 1; j < position - 1; j++)
        {
            _count *= 10;
        }

        if (position == 15 && (_number / _count == 34 || _number / _count == 37))
        {
            printf("AMEX\n");
        }
        else if ((position == 13 || position == 16) && ((_number / _count) / 10 == 4))
        {
            printf("VISA\n");
        }
        else if (position == 16 && (_number / _count == 51 || _number / _count == 52 || _number / _count == 53 ||
                                    _number / _count == 54 || _number / _count == 55))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}