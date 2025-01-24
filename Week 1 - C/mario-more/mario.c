#include <stdbool.h>
#include <stdio.h>

int get_size();
void display_pyramid(int n);

int main(void)
{
  int size = get_size();
  display_pyramid(size);
}

int get_size()
{
  int n;
  char ch;

  while (true)
  {
    printf("Height: ");
    
    if (scanf("%d", &n) == 1 && n > 0)
    {
      return n;
    }
    else
    {
      while ((ch = getchar()) != '\n' && ch != EOF);
    }
  }
}

void display_pyramid(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (j >= n - i - 1)
      {
        printf("#");
      }
      else
      {
        printf(" ");
      }
    }

    printf(" ");

    for (int j = 0; j <= i; j++) {
      printf("#");
    }

    printf("\n");
  }
}