#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void to_binary(int number);

int main(void)
{
    // TODO
    string message = get_string("Message: ");
    int message_length = strlen(message);
    for (int i = 0; i < message_length; i++)
    {
        to_binary(message[i]);
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

void to_binary(int number)
{
    int binaryNum[8];
    for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
    {
        binaryNum[j] = number % 2;
        number = number / 2;
    }
    for (int k = 0; k < BITS_IN_BYTE; k++)
    {
        print_bulb(binaryNum[k]);
    }
    printf("\n");
}
