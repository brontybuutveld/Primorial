#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gmp.h>
#include "input.h"
#include "findPrimes.h"
#include "multiplication.h"

int main (int argc, char *argv[]) {

    input();

    unsigned int primeCount, temp3 = (x * 1.15) / log(x);
    unsigned int *primes = malloc(temp3 * sizeof(unsigned int));
    FILE *f;
    if (printFile) {
        f = fopen(filename, "w");
        if (f == NULL) {
            puts("Error opening file!");
            return 1;
        }
    }

    primeCount = findPrimes(f, primes);

    if (!primorial) {
        for(int i = 0; i < primeCount; i++) {
            int temp = primes[i];
            while(temp * primes[i] <= x) {
                temp *= primes[i];
            }
            if (primes[i] == temp) {
                break;
            }
        }
    }

    multiplication(primeCount, f, primes);
    fclose(f);
    free(primes);
    return 0;
}
