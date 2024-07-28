#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <gmp.h>

#include "input.h"

int findPrimes(FILE *f, unsigned int *primes) {
    unsigned int primeCount = 0;
    if (printPrimes) {
        if (printFile)
            fprintf(f, "[");
        else
            printf("[");
    }
    const char *comma = "";
    for (int i = 2; i <= x; i++) {
        if(progress && i % (x/100) == 0)
            printf("%d%%\n", i / (x/100));
        int y = sqrt(i);
        bool notPrime = false;
        for(int j = 2; j <= y; j++) {
            if(i % j == 0) {
                notPrime = true;
                break;
            }
        }

        if (notPrime) {
            continue;
        }
        primes[primeCount] = i;
        primeCount++;

        if(printPrimes) {
            if (printFile)
                fprintf(f, "%s%d", comma, i);
            else
                printf("%s%d", comma, i);
            comma = ",";
        }
    }
    if (printPrimes) {
        if (printFile)
            fprintf(f, "]\n");
        else
            printf("]\n");
    }
    return primeCount;
}