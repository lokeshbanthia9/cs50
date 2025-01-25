/**
 * Encrypts messages using Caesar’s cipher.
 * 
 * https://cs50.harvard.edu/x/2025/psets/2/caesar/
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int max_text_length = 50;

bool is_positive_integer(char *str);
char *encrypt(char *plain_text, int key, int length);

int main(int argc, char *argv[])
{
  if (argc != 2 || !is_positive_integer(argv[1]))
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }

  char *plain_text = (char *)malloc((max_text_length + 1) * sizeof(char));
  char *cipher_text = (char *)malloc(max_text_length * sizeof(char));
  if (plain_text == NULL || cipher_text == NULL)
  {
    printf("Memory allocation failed\n");
    return 1;
  }

  printf("plaintext: ");
  fgets(plain_text, max_text_length, stdin);

  int length = strlen(plain_text);
  cipher_text = encrypt(plain_text, atoi(argv[1]), length);

  if(!cipher_text)
  {
    printf("Memory allocation failed\n");
    return 1;
  }

  printf("ciphertext: %s\n", cipher_text);

  free(plain_text);
  free(cipher_text);

  return 0;
}

// Checks if the string is a positive integer
bool is_positive_integer(char *str)
{
  if (str == NULL || *str == '\0')
  {
    return false;
  }

  while (*str)
  {
    if (!isdigit(*str))
    {
      return false;
    }
    str++;
  }

  return true;
}


// Encrypts the string using Caesar’s algorithm
char *encrypt(char *plain_text, int key, int length)
{
  char *cipher_text = (char *)malloc((length + 1) * sizeof(char));
  if (cipher_text == NULL)
  {
    return NULL;
  }

  for (int i = 0; *plain_text; i++, plain_text++)
  {
    char c = *plain_text;

    if (isupper(c))
    {
      int old = c - 65;
      int new = (old + key) % 26;
      cipher_text[i] = (char) new + 65;
    }
    else if (islower(c))
    {
      int old = c - 97;
      int new = (old + key) % 26;
      cipher_text[i] = (char) new + 97;
    }
    else
    {
      cipher_text[i] = c;
    }
  }

  cipher_text[length] = '\0';
  return cipher_text;
}