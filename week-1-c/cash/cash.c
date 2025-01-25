/**
 * Prints the minimum number of coins required for the change owed.
 * 
 * https://cs50.harvard.edu/x/2025/psets/1/cash/
 */

#include <stdbool.h>
#include <stdio.h>

const int number_of_change = 4;
const int change_list_desc[] = {25, 10, 5, 1};

int get_amount();
int calculate_minimum_coins(int amount);

int main(void)
{
  int amount = get_amount();
  int coins = calculate_minimum_coins(amount);
  printf("%d\n", coins);
}


// Get the change owed amount
int get_amount()
{
  int n;
  char ch;

  while (true)
  {
    printf("Change owed: ");

    if (scanf("%d", &n) == 1 && n >= 0)
    {
      return n;
    }
    else
    {
      while ((ch = getchar()) != '\n' && ch != EOF);
    }
  }
}

// Calculate minimum number of coins required for the owed amount
int calculate_minimum_coins(int amount)
{
  int coins = 0;

  for (int i = 0; i < number_of_change; i++)
  {
    while (amount > 0 && change_list_desc[i] <= amount)
    {
      amount -= change_list_desc[i];
      coins++;
    }
  }

  return coins;
}