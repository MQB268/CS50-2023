#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

char LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
bool is_letter(char character);

int main(void)
{
    // Ask user to input text
    string text = get_string("Text: ");

    // Count number of letters in the text
    int number_of_letter = count_letters(text);
    int number_of_word = count_words(text);
    int number_of_sentence = count_sentences(text);
    float index = (0.0588 * (((float) number_of_letter / number_of_word) * 100)) -
                  (0.296 * (((float) number_of_sentence / number_of_word) * 100)) - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_letters(string text)
{
    int text_length = strlen(text);
    int count = 0;
    for (int i = 0; i < text_length; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (toupper(text[i]) == LETTERS[j])
            {
                count++;
            }
        }
    }
    return count;
}

int count_words(string text)
{
    int text_length = strlen(text);
    int count = 0;
    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == ' ' ||
            (is_letter(text[i]) && (text[i + 1] == '.' || text[i + 1] == '!' || text[i + 1] == '?') && text[i + 2] != ' '))
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string text)
{
    int text_length = strlen(text);
    int count = 0;
    for (int i = 0; i < text_length; i++)
    {
        if ((is_letter(text[i]) && text[i + 1] == '.') || (is_letter(text[i]) && text[i + 1] == '!') ||
            (is_letter(text[i]) && text[i + 1] == '?'))
        {
            count++;
        }
    }
    return count;
}

bool is_letter(char character)
{
    for (int i = 0; i < 26; i++)
    {
        if (toupper(character) == LETTERS[i])
        {
            return true;
        }
    }
    return false;
}
