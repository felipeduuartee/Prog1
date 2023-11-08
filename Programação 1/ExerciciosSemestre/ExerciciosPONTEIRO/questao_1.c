#include <stdio.h>

int main() {

  int x = 10;
  float y = 3.14;
  char z = 'a';

  int *p_x = &x;
  float *p_y = &y;
  char *p_z = &z;

  printf("x = %d\n", x);
  printf("y = %f\n", y);
  printf("z = %c\n", z);

  // Modifica os valores das variáveis usando os ponteiros
  *p_x = 20;
  *p_y = 2.71828;
  *p_z = 'b';

  // Imprime os valores das variáveis após a modificação
  printf("x = %d\n", x);
  printf("y = %f\n", y);
  printf("z = %c\n", z);

  return 0;
}
