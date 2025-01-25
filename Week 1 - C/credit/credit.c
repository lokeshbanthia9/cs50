/**
 * Checks the validity of a credit card number and prints whether it is a valid American Exchange, Mastercard or Visa card number.
 */

#include <stdbool.h>
#include <stdio.h>

long long get_card_number();
int calculate_card_number_digits(long long n);
bool validate_card_number(long long num, int digits);
bool is_amex(long long num, int digits);
bool is_mastercard(long long num, int digits);
bool is_visa(long long num, int digits);

int main(void)
{
  long long card_number = get_card_number();
  int digits = calculate_card_number_digits(card_number);

  if (!validate_card_number(card_number, digits))
  {
    printf("INVALID\n");
    return 1;
  }

  if (is_amex(card_number, digits))
  {
    printf("AMEX\n");
    return 0;
  }
  else if (is_mastercard(card_number, digits))
  {
    printf("MASTERCARD\n");
    return 0;
  }
  else if (is_visa(card_number, digits))
  {
    printf("VISA\n");
    return 0;
  }
  else
  {
    printf("INVALID\n");
    return 1;
  }
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

// Calculate the number of digits in the number
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

// Returns the first two digits of a positive number
int get_first_two_digits(long long num)
{
  while (num > 100)
  {
    num /= 10;
  }

  return num;
}

// Checks if the number is a valid American Exchange card number
bool is_amex(long long num, int digits)
{
  int first_two_digits = get_first_two_digits(num);

  if (digits == 15 && (first_two_digits == 34 || first_two_digits == 37))
  {
    return true;
  }

  return false;
}

// Checks if the number is a valid Mastercard card number
bool is_mastercard(long long num, int digits)
{
  int first_two_digits = get_first_two_digits(num);

  if (digits == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
  {
    return true;
  }

  return false;
}

// Checks if the number is a valid Visa card number
bool is_visa(long long num, int digits)
{
  int first_digit = get_first_two_digits(num) / 10;

  if ((digits == 13 || digits == 16) && first_digit == 4)
  {
    return true;
  }

  return false;
}