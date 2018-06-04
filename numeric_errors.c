#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int add(int x, int y, int* oflow){
  *oflow = 0;
  if (x > 0 && y > INT_MAX - x) {
    *oflow = 1;
  } else if (x < 0 && y < INT_MIN - x) {
    *oflow = 1;
  }
  return x + y;
}

int subtract(int x, int y, int* oflow){
  *oflow = 0;
  if (y > 0 && x < y + INT_MIN) {
    *oflow = 1;
  } else if (y < 0 && x > y + INT_MAX) {
    *oflow = 1;
  }
  return x - y;
}

int multiply(int x, int y, int* oflow) {
  // *multiply* is harder because many cases have to be handled  
  *oflow = 0;
  if (x > 0 && y > 0 && x > (INT_MAX / y))
    *oflow = 1;
  else if (x > 0 && y <= 0  && y < (INT_MIN / x))
    *oflow = 1;
  else if (x <= 0  && y > 0 && x < (INT_MIN / y))
    *oflow = 1;
  else if (x <= 0  && y <= 0 && x != 0 && y < (INT_MAX / x))
    *oflow = 1;  

  return x * y;
}

int divide(int x, int y, int* oflow) {
  // Only a single case is to be handled
  *oflow = 0;
  if (y == 0 || (x == INT_MIN && y == -1)) {
    *oflow = 1;
    return 0;
  } else {
    return x / y;
  }

}

void add_helper(int x, int y, int sum, int* oflow) {
  x = 2455;
  y = 892;
  sum = add(x, y, oflow);
  if (! *oflow) printf("x:%d + y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d + y:%d = OVERFLOW\n", x, y);

  x = INT_MAX;
  y = INT_MAX;
  sum = add(x, y, oflow);
  if (! *oflow) printf("x:%d + y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d + y:%d = OVERFLOW\n", x, y);

  x = INT_MIN;
  y = INT_MIN;
  sum = add(x, y, oflow);
  if (! *oflow) printf("x:%d + y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d + y:%d = OVERFLOW\n", x, y);

  x = INT_MAX;
  y = INT_MIN;
  sum = add(x, y, oflow);
  if (! *oflow) printf("x:%d + y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d + y:%d = OVERFLOW\n", x, y);

  x = INT_MAX;
  y = 10;
  sum = add(x, y, oflow);
  if (! *oflow) printf("x:%d + y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d + y:%d = OVERFLOW\n", x, y);
}

void subtract_helper(int x, int y, int sum, int* oflow) {
  x = 2455;
  y = 892;
  sum = subtract(x, y, oflow);
  if (! *oflow) printf("x:%d - y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d - y:%d = OVERFLOW\n", x, y);

  x = INT_MAX;
  y = INT_MAX;
  sum = subtract(x, y, oflow);
  if (! *oflow) printf("x:%d - y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d - y:%d = OVERFLOW\n", x, y);

  x = INT_MAX;
  y = - INT_MAX;
  sum = subtract(x, y, oflow);
  if (! *oflow) printf("x:%d - y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d - y:%d = OVERFLOW\n", x, y);

  x = INT_MIN;
  y = INT_MIN;
  sum = subtract(x, y, oflow);
  if (! *oflow) printf("x:%d - y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d - y:%d = OVERFLOW\n", x, y);

  x = INT_MAX;
  y = INT_MIN;
  sum = subtract(x, y, oflow);
  if (! *oflow) printf("x:%d - y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d - y:%d = OVERFLOW\n", x, y);

  x = 0;
  y = INT_MIN;
  sum = subtract(x, y, oflow);
  if (! *oflow) printf("x:%d - y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d - y:%d = OVERFLOW\n", x, y);
}

void multiply_helper(int x, int y, int sum, int* oflow) {
  x = 23;
  y = 244;
  sum = multiply(x, y, oflow);
  if (! *oflow) printf("x:%d * y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d * y:%d OVERFLOW\n", x, y);

  x = 0;
  y = INT_MAX;
  sum = multiply(x, y, oflow);
  if (! *oflow) printf("x:%d * y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d * y:%d OVERFLOW\n", x, y);

  x = INT_MIN;
  y = INT_MIN;
  sum = multiply(x, y, oflow);
  if (! *oflow) printf("x:%d * y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d * y:%d OVERFLOW\n", x, y);

  x = -100;
  y = 0;
    sum = multiply(x, y, oflow);
  if (! *oflow) printf("x:%d * y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d * y:%d OVERFLOW\n", x, y);
  
}

void divide_helper(int x, int y, int sum, int* oflow) {
  x = 23;
  y = 244;
  sum = divide(x, y, oflow);
  if (! *oflow) printf("x:%d / y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d / y:%d OVERFLOW\n", x, y);

  x = 0;
  y = INT_MIN;
  sum = divide(x, y, oflow);
  if (! *oflow) printf("x:%d / y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d / y:%d OVERFLOW\n", x, y);

  x = INT_MAX;
  y = 0;
  sum = divide(x, y, oflow);
  if (! *oflow) printf("x:%d / y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d / y:%d OVERFLOW\n", x, y);

  x = INT_MAX;
  y = -1;
  sum = divide(x, y, oflow);
  if (! *oflow) printf("x:%d / y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d / y:%d OVERFLOW\n", x, y);

  x = INT_MIN;
  y = -1;
  sum = divide(x, y, oflow);
  if (! *oflow) printf("x:%d / y:%d = sum:%d\n", x, y, sum);
  else printf("x:%d / y:%d OVERFLOW\n", x, y);

}


int main() {

  int* oflow = (int*) malloc(sizeof(int));
  int x, y, sum;
  printf("INT_MAX: %d, INT_MIN: %d\n", INT_MAX, INT_MIN);

  printf("... EX1: Add function ... \n");
  add_helper(x, y, sum, oflow);
  printf("\n");
  
  printf("... EX2: Subtract function ... \n");
  subtract_helper(x, y, sum, oflow);
  printf("\n");

  printf("... EX3: Multiply function ... \n");
  multiply_helper(x, y, sum, oflow);
  printf("\n");

  printf("... EX4: Divide function ... \n");
  divide_helper(x, y, sum, oflow);
  printf("\n");
 
  return 0;
}
