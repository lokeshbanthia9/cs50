/**
 * Determines the winner of a Scrabble-like game.
 * 
 * https://cs50.harvard.edu/x/2025/psets/2/scrabble/
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int max_word_size = 50;
const int word_points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculate_word_score(char word[]);

int main(void)
{
  char player_1_word[max_word_size];
  char player_2_word[max_word_size];

  printf("Player 1: ");
  scanf("%s", player_1_word);

  printf("Player 2: ");
  scanf("%s", player_2_word);

  int player_1_score = calculate_word_score(player_1_word);
  int player_2_score = calculate_word_score(player_2_word);

  if (player_1_score > player_2_score)
  {
    printf("Player 1 wins!");
  }
  else if (player_1_score < player_2_score)
  {
    printf("Player 2 wins!");
  }
  else
  {
    printf("Tie");
  }

  return 0;
}

// Calculate the total points of all the letters in the word using `word_points` array
int calculate_word_score(char word[])
{
  int length = strlen(word);
  int score = 0;

  for(int i = 0; i < length; i++)
  {
    char c = toupper(word[i]);
    if (c >= 'A' && c <= 'Z')
    {
      score += word_points[c - 65];
    }
  }

  return score;
}