#include <stdio.h>
#include <limits.h>
#include <math.h>

/***
 * maximum value that can be used do calculare c without overflow
 **/
#define calc_lim ((sqrt(ULLONG_MAX) / sqrt(2)))

#define calc_a(u,v) ((u * u) - (v * v))
#define calc_b(u,v) (2 * u * v)
#define calc_c(u,v) ((u * u) + (v * v))

/***
 * @return 1 if prime 0 otherwise
 **/
int is_prime(unsigned long long num)
{
  unsigned long long i;
  for (i = 2; i <= sqrt(num); i++)
  {
    if (num % i == 0)
	 return 0;
  }
  return 1;
}

int main(void)
{
  unsigned long long a;
  unsigned long long b;
  unsigned long long c;

  unsigned long long u;
  unsigned long long v;
  
  for (v = 1; v <= calc_lim; v++)
    {
      for (u = v + 1; u <= calc_lim; u++)
	{
	  //	  printf("u: %llu v: %llu\n", u,v);
	  
	  a = calc_a(u,v);
	  b = calc_b(u,v);
	  c = calc_c(u,v);

	  //	  printf("testing: (%llu, %llu, %llu)\n", a,b,c);

	  if ((is_prime(a) + is_prime(b) + is_prime(c)) >= 2)
	    fprintf(stdout, "(%llu, %llu, %llu)\n", a, b, c);
	}
    }
  return 1;
}
