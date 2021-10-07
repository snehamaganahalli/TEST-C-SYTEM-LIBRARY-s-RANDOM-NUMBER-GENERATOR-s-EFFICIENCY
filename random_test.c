#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
typedef unsigned int uint32_t;

uint32_t ecluidean_gcd(uint32_t x, uint32_t y)
{
  uint32_t temp;

  if (x < y)
  {
    temp = y;
    y = x;
    x = temp;
  }

  while (x % y != 0)
  {
    x += y;
    y = x - y;
    x = x - y;
    y %= x;
  }

  return y;
}

float square_root(float x)
{
  return sqrt(x);
}

float calculate_pi(float probability)
{
  float temp;

  temp = 6.0f/probability;
  return square_root (temp);
}

int main(int argc, char *argv[])
{
  uint32_t x;
  uint32_t y;
  uint32_t res;
  uint32_t i;
  uint32_t count = 0;
  float probability;
  float pi;

  if (argc != 2)
  {
    printf("\nUsage: ./a.out <value>");
    printf("\nHere the 'value' represent the number of times you would like to calculate GCD\n");
    return 0;
  }

  uint32_t max_times = atoi(argv[1]);
  if (max_times > UINT_MAX)
  {
    printf("\nPlease provide a the 'value' lesser than %u", UINT_MAX);
    printf("\nUsage: ./a.out <value>");
    printf("\nHere the 'value' represent the number of times you would like to calculate GCD\n");
    return 0;
  }

  printf ("\nCalculating GCD!!!!!!!!!!. if it is taking more time then try with a smaller 'value'");
  for(i = 0; i< max_times; i++)
  {
    x = rand();
    y = rand();
    res = ecluidean_gcd(x, y);
    if (res == 1)
      count ++;
  }

  probability = (float)count / (float)max_times;
  pi = calculate_pi(probability);


  printf ("\nThe number of times the GCD is equal to 1 is %u out of %u times", count, max_times);
  printf ("\nThe probability of GDB equal to 1 is %f", probability);
  printf ("\n**********************************************************\n");
  printf ("\nThe value of PI is: %f", pi);
  printf ("\n**********************************************************\n");
  printf("\nTo get the value of PI to equal to 3.14, you need to try GCD on many samples. To try GCD many times follow the below command");
  printf("\nUsage: ./a.out <value>");
  printf("\nHere the 'value' represent the number of times you would like to calculate GCD\n");
  return 0;
}
