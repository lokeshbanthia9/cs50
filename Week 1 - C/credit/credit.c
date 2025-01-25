/**
 * Checks the validity of a credit card number and prints whether it is a valid American Exchange, Mastercard or Visa card number.
 */

#include <stdbool.h>
#include <stdio.h>

long long get_card_number();
int calculate_card_number_digits(long long n);
bool validate_card_number(long long num, int digits);

int main(void)
{
  long long card_number = get_card_number();

  int digits = calculate_card_number_digits(card_number);
  if (digits != 13 && digits != 15 && digits != 16)
  {
    printf("INVALID\n");
    return 1;
  }

  if (!validate_card_number(card_number, digits))
  {
    printf("INVALID\n");
    return 1;
  }

  // Find the first two digits of the card number
  while (card_number > 100)
  {
    card_number /= 10;
  }

  // Check for American Exchange card
  if (digits == 15 && (card_number == 34 || card_number == 37))
  {
    printf("AMEX\n");
    return 0;
  }

  // Check for Mastercard card
  if (digits == 16 && (card_number >= 51 && card_number <= 55))
  {
    
    printf("MASTERCARD\n");
    return 0;
  }

  // Find the first digit of the card number
  card_number /= 10;

  // CHeck for Visa card
  if ((digits == 13 || digits == 16) && card_number == 4)
  {
    printf("VISA\n");
    return 0;
  }

  // When all cases fail
  printf("INVALID\n");
  return 1;
}


// Get the credit card number
long long get_card_number()
{
  long long n;
  char ch;

  while (true)
  {
    printf("Number: ");

    if (scanf("%lld", &n) == 1 && n >= 0)
    {
      return n;
    }
    else
    {
      while ((ch = getchar()) != '\n' && ch != EOF);
    }
  }
}

// Calculate the number of digits in the long number
int calculate_card_number_digits(long long num)
{
  int digits = 0;

  while (num > 0)
  {
    num /= 10;
    digits++;
  }

  return digits;
}

// Validates the card number based on Luhn’s algorithm
bool validate_card_number(long long num, int digits)
{ 
  int sum = 0;

  for (int i = 0; i < digits; i++)
  {
    int digit = num % 10;

    if (i % 2 == 0)
    {
      sum += digit;
    }
    else
    {
      int product = digit * 2;
      sum += (product / 10) + (product % 10);
    }

    num /= 10;
  }

  return sum % 10 == 0;
}