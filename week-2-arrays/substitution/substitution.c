/**
 * Encrypts messages using a substitution cypher.
 * 
 * https://cs50.harvard.edu/x/2025/psets/2/substitution/
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int number_of_letters = 26;
const int max_text_length = 50;

bool validate_key(char *key);
char *encrypt(char *key, char *plain_text);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }

  if (!validate_key(argv[1]))
  {
    printf("Key must contain 26 unique alphabet characters.");
    return 1;
  }

  char *plain_text = (char *)malloc((max_text_length + 1) * sizeof(char));
  char *cipher_text = (char *)malloc((max_text_length + 1) * sizeof(char));
  if (plain_text == NULL || cipher_text == NULL)
  {
    printf("Memory allocation failed\n");
    return 1;
  }

  printf("plaintext: ");
  fgets(plain_text, max_text_length, stdin);

  cipher_text = encrypt(argv[1], plain_text);
  if (cipher_text == NULL)
  {
    printf("Memory allocation failed\n");
    return 1;

  }

  printf("ciphertext: %s\n", cipher_text);

  free(plain_text);
  free(cipher_text);

  return 0;
}

// Validates the substitution key to contain only 26 alphabet letters exactly once
bool validate_key(char *key)
{
  if (key == NULL || *key == '\0')
  {
    return false;
  }

  if (strlen(key) != number_of_letters)
  {
    return false;
  }

  bool includes_letter[number_of_letters];
  for (int i = 0; i < number_of_letters; i++)
  {
    includes_letter[i] = false;
  }

  for (int i = 0; i < number_of_letters; i++, key++)
  {
    if (isalpha(*key))
    {
      char c = tolower(*key);
      int index = c - 'a';

      if (!includes_letter[index])
      {
        includes_letter[index] = true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }  

  return true;
}

// Encrypts the text using substituiton method
char *encrypt(char *key, char *plain_text)
{
  int length = strlen(plain_text);
  char *cipher_text = (char *)malloc((length + 1) * sizeof(char));
  if (cipher_text == NULL)
  {
    return NULL;
  }

  for (int i = 0; i < length; i++, plain_text++)
  {
    char c = *plain_text;

    if (isupper(c))
    {
      int index = c - 'A';
      cipher_text[i] = toupper(key[index]);
    }
    else if (islower(c))
    {
      int index = c - 'a';
      cipher_text[i] = tolower(key[index]);
    }
    else
    {
      cipher_text[i] = c;
    }
  }

  cipher_text[length] = '\0';
  return cipher_text;
}