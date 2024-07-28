#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "input.h"

void multiplication (int primeCount, FILE *f, unsigned int *primes) {
    mpz_t product1, product2, product3, product4, product5, product6, product7, product8;
    mpz_init_set_d(product1, 1);
    mpz_init_set_d(product2, 1);
    mpz_init_set_d(product3, 1);
    mpz_init_set_d(product4, 1);
    mpz_init_set_d(product5, 1);
    mpz_init_set_d(product6, 1);
    mpz_init_set_d(product7, 1);
    mpz_init_set_d(product8, 1);

    for (int i = 0; i < primeCount; i += 8) {
        mpz_mul_ui(product1, product1, primes[i]);
        if (i + 1 < primeCount)
            mpz_mul_ui(product2, product2, primes[i + 1]);
        if (i + 2 < primeCount)
            mpz_mul_ui(product3, product3, primes[i + 2]);
        if (i + 3 < primeCount)
            mpz_mul_ui(product4, product4, primes[i + 3]);
        if (i + 4 < primeCount)
            mpz_mul_ui(product5, product5, primes[i + 4]);
        if (i + 5 < primeCount)
            mpz_mul_ui(product6, product6, primes[i + 5]);
        if (i + 6 < primeCount)
            mpz_mul_ui(product7, product7, primes[i + 6]);
        if (i + 7 < primeCount)
            mpz_mul_ui(product8, product8, primes[i + 7]);
        if (i % (primeCount / 800) == 0)
            printf("%d%%\n", i * 100 / primeCount);
    }

    mpz_mul(product1, product2, product1);
    mpz_mul(product3, product4, product3);
    mpz_mul(product5, product6, product5);
    mpz_mul(product7, product8, product7);

    mpz_mul(product1, product1, product3);
    mpz_mul(product5, product7, product5);

    mpz_mul(product1, product5, product1);

    if (test) {
        for(unsigned int i = 2; i <= x; i++) {
            mpz_mod_ui(product8, product1, i);
            if(mpz_cmp_d(product8, 0) == 0)
                continue;
            else {
                puts("Answer found wanting");
                exit(1);
            }
        }
    }
    if (printFile)
        gmp_fprintf(f, "%Zd\n", product1);
    else
        gmp_printf("%Zd\n", product1);
    mpz_clear(product1);
    mpz_clear(product2);
    mpz_clear(product3);
    mpz_clear(product4);
    mpz_clear(product5);
    mpz_clear(product6);
    mpz_clear(product7);
    mpz_clear(product8);
}
