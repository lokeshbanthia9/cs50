/**
 * Calculates the approximate grade level needed to comprehend some text.
 * 
 * https://cs50.harvard.edu/x/2025/psets/2/readability/
 */

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

const int max_text_characters = 1000;

int count_letters(char text[]);
int count_words(char text[]);
int count_sentences(char text[]);
double calculate_grade_index(int letters, int words, int sentences);

int main(void)
{
  char text[max_text_characters];
  printf("Text: ");
  fgets(text, sizeof(text), stdin);

  int letters = count_letters(text);
  int words = count_words(text);
  int sentences = count_sentences(text);

  double grade_index = calculate_grade_index(letters, words, sentences);
  int grade = round(grade_index);

  if (grade < 1)
  {
    printf("Before Grade 1\n");
  }
  else if (grade >= 16)
  {
    printf("Grade 16+\n");
  }
  else
  {
    printf("Grade %d\n", grade);
  }

  return 0;
}

// Counts the number of alphabets in the text
int count_letters(char text[])
{
  int count = 0;

  for (int i = 0; text[i] != '\0'; i++)
  {
    if (isalpha(text[i]))
    {
      count++;
    }
  }
  
  return count;
}

// Couns the number of words in the text (words are assumed to be separted by blank space)
int count_words(char text[])
{
  int count = 0;
  bool in_word = false;

  for (int i = 0; text[i] != '\0'; i++)
  {
    if (isalpha(text[i]) && !in_word)
    {
      count++;
      in_word = true;
    }
    else if (isspace(text[i]))
    {
      in_word = false;
    }
  }

  return count;
}

// Counts the number of sentences in the text (a sentence is assumed to end by period `.`, exclamation `!` or question `?`)
int count_sentences(char text[])
{
  int count = 0;
  bool in_sentence = false;

  for (int i = 0; text[i] != '\0'; i++)
  {
    if ((text[i] == '.' || text[i] == '!' || text[i] == '?') && in_sentence)
    {
      count++;
      in_sentence = false;
    }
    else if (isalpha(text[i]) && !in_sentence)
    {
      in_sentence = true;
    }
  }

  return count;
}

// Calculates the grade index of the text based on Coleman-Liau index
double calculate_grade_index(int letters, int words, int sentences)
{
  double L = (double) letters * 100 / words;
  double S = (double) sentences * 100 / words;
  return 0.0588 * L - 0.296 * S - 15.8;
}