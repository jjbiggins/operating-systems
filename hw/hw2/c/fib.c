/* fib.c by Joe Biggins */
#include <stdio.h>
#include <stdlib.h>


int fib( int n ) {
        int i = 0;
        int j = 1;
        while (n > 0) {
                int k = i + j;
                i = j;
                j = k;
                n = n - 1;
        }
        return i;
}

int main(void) {
	int n = 18;
	int fib_n;
	fib_n = fib(n);
	printf("the 18th fibonacci number is %d\n", fib_n);
	return 0;
}
