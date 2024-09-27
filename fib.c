
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

unsigned long long fib_r_core(unsigned long long nFind);
unsigned long long fib_i_core(unsigned long long nFind);
unsigned long long fib_r_wrapper(unsigned long long n);
unsigned long long fib_i_wrapper(unsigned long long n);



unsigned long long int fib_i_wrapper(unsigned long long int n) {
   if (n == 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }
   unsigned long long int firstPrevious = 0;
   unsigned long long int secondPrevious = 1;
   unsigned long long int fibonacciSum = 1;
   for (unsigned long long int ix = 3; ix <= n; ix++) {
      fibonacciSum = firstPrevious + secondPrevious;
      firstPrevious = secondPrevious;
      secondPrevious = fibonacciSum;
   }
   return fibonacciSum;
}

static unsigned long long int memocache[1000] = {0};


unsigned long long int fib_r_wrapper(unsigned long long int n) {
   if (n <= 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }
   return fib_r_core(n - 1) + fib_r_core(n - 2);
}

unsigned long long int fib_i_core(unsigned long long nFind) {
   if (memocache[nFind] != 0) {
      return memocache[nFind];
   }
   memocache[nFind] = fib_i_core(nFind);
   return memocache[nFind];
}

unsigned long long int fib_r_core(unsigned long long nFind) {
   if (memocache[nFind] != 0) {
      return memocache[nFind];
   }
   memocache[nFind] = fib_r_wrapper(nFind);
   return memocache[nFind];
}


int main(int argc, char *argv[]) {
   int firstFibNumber;
   firstFibNumber = atoi(argv[1]);
   char method = argv[2][0];
      
   if (method == 'i') {
      // here do the iterative method
      printf("%lld\n", (fib_i_memo(firstFibNumber)));
   } else {
      // here do the recursive method
      //printf("This is the Recursive method up to: %d\n", fibonacciNum);
      printf("%lld\n", (fib_r_memo(firstFibNumber)));
   }
   return 0;
}
