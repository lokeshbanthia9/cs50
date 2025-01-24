#include <stdio.h>

int get_size();
void display_pyramid(int n);

int main(void)
{
  int size = get_size();
  display_pyramid(size);
}

// Get the pyramid size
int get_size()
{
  int n;
  do
  {
    printf("Height: ");
    scanf("%d", &n);
  } while (n <= 0);
  
  return n;
}

// Print the block pyramid
void display_pyramid(int n)
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j >= n - i - 1) 
      {
        printf("#");
      }
      else
      {
        printf(" ");
      }
    }

    printf("\n");
  }
}