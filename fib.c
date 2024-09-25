
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// changes for memoization!
/*
   - needed for both iterative and recursive
   - duplicate the memoization code for both i and r
   - rename underlying fib() routines to fib_i_core for example
*/


unsigned long long int fib_i_core(unsigned long long int n) {
   if (n == 1) {
      printf("0");
      return 0;
   } else if (n == 2) {
      printf("1");
      return 0;
   }
   unsigned long long int firstPrevious = 0;
   unsigned long long int secondPrevious = 1;
   unsigned long long int fibonacciSum = 1;
   for (unsigned long long int i = 3; i <= n; i++) {
      fibonacciSum = firstPrevious + secondPrevious;
      firstPrevious = secondPrevious;
      secondPrevious = fibonacciSum;
   }
   return fibonacciSum;
}


unsigned long long int fib_r_core(unsigned long long int n) {
   if (n <= 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }
   return fib_r_core(n - 1) + fib_r_core(n - 2);
}
unsigned long long int iter_memocache[1000] = {0};

unsigned long long int fib_i_memo(int nFind) {
   if (iter_memocache[nFind] != 0) {
      return iter_memocache[nFind];
   }
   iter_memocache[nFind] = fib_i_core(nFind);
   return iter_memocache[nFind];
}

unsigned long long int recur_memocache[1000] = {0};

unsigned long long int fib_r_memo(int nFind) {
   if (recur_memocache[nFind] != 0) {
      return recur_memocache[nFind];
   }
   recur_memocache[nFind] = fib_r_core(nFind);
   return recur_memocache[nFind];
}


int main(int argc, char *argv[]) {
   int firstFibNumber;
   firstFibNumber = atoi(argv[1]);
   char method = argv[2][0];
      
   if (method == 'i') {
      // here do the iterative method
      printf("%lld", (fib_i_memo(firstFibNumber)));
   } else {
      // here do the recursive method
      //printf("This is the Recursive method up to: %d\n", fibonacciNum);
      printf("%lld", (fib_r_memo(firstFibNumber)));
   }
   return 0;
}
