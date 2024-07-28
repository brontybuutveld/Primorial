#include <stdbool.h>
#include <stdio.h>

unsigned int x;
bool primorial, printPrimes, printFile, test, progress;
char filename[100];


void input () {
    char input;

    puts("Run default? (y/n)");
    scanf("%c", &input);
    if (input == 'y') {
        primorial = false;
        printPrimes = false;
        printFile = false;
        test = false;
        progress = true;
        x = 10000000;
        return;
    }
    puts("LCM or primorial? (l/p)");
    scanf(" %c", &input);
    if (input == 'p') {
        primorial = true;
        puts("Validate answer? (y/n)");
        scanf(" %c", &input);
        if (input == 'y')
            test = true;
        else
            test = false;
    } else {
        primorial = false;
    }

    printf("Upperbound: ");
    scanf(" %d", &x);

    puts("Print list of primes (y/n)");
    scanf(" %c", &input);
    if (input == 'y')
        printPrimes = true;
    else
        printPrimes = false;

    puts("Output to file? (y/n)");
    scanf(" %c", &input);
    if (input == 'y') {
        printFile = true;
        printf("Filename: ");
        scanf(" %s", filename);
    } else
        printFile = false;

    puts("Progress bar? (y/n)");
    scanf(" %c", &input);
    if (input == 'y')
        progress = true;
    else
        progress = false;
}