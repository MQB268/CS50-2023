#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char UPPER_LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char LETTERS[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int k = 0; k < strlen(argv[1]); k++)
    {
        if (!isalpha(argv[1][k]))
        {
            return 1;
        }

        for (int m = k + 1; m < strlen(argv[1]); m++)
        {
            if (argv[1][k] == argv[1][m])
            {
                return 1;
            }
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
                    ciphertext[i] = text[i] == UPPER_LETTERS[j] ? toupper(argv[1][j]) : tolower(argv[1][j]);
                }
            }
        }
    }

    printf("ciphertext: %s\n", ciphertext);
}
