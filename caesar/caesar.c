#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char UPPER_LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char LETTERS[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    string text = get_string("plaintext: ");
    char ciphertext[strlen(text)];
    strcpy(ciphertext, text);

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (text[i] == UPPER_LETTERS[j] || text[i] == LETTERS[j])
                {
                    int c = j + 1 + (atoi(argv[1]) % 26);
                    c = c > 26 ? c - 26 : c;
                    ciphertext[i] = text[i] == UPPER_LETTERS[j] ? UPPER_LETTERS[c - 1] : LETTERS[c - 1];
                }
            }
        }
    }

    printf("ciphertext: %s\n", ciphertext);
}
