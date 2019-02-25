/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */
#include "deletable_primes.h"
#include <math.h>

bool is_prime(unsigned long n){
  if (n <= 1)
   {
       return false;
   }
   int j=0;
   for (j = 2; j <= n / 2; j++)
   {
       if ((n % j) == 0)
       {
           return false;
       }
   }
 return true;
}

unsigned long remove_digit(int index,unsigned long n){
  long numPow=pow(10,index);
  unsigned long num;
  num = n/(numPow*10)*numPow+(n%numPow);
  return num;
}

int get_ways(unsigned long n){

  if (n<10 && is_prime(n)) {
    return 1;
  }
  int way=0;
  for (int i = 0; i < get_lengh(n); i++) {
    if(is_prime(remove_digit(i,n))){
      way+=get_ways(remove_digit(i,n));
    }
  }
 return way;

}

int get_lengh(unsigned long n){
 int lengh=0;
 while (n>1) {
   n/=10;
   lengh++;
 }
 return lengh;

}
