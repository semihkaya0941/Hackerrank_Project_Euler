#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long *to_long_Array(char *numberString, long n);

long largest_production(long *array, long number_of_conscutive, long n);

int main() {
    long test_case;

    scanf("%ld", &test_case);
    for (long a0 = 0; a0 < test_case; a0++) {
        long n;
        char *real_number;
        long k;
        scanf("%ld %ld", &n, &k);
        real_number = malloc(n * sizeof(char));
        scanf("%s", real_number);

        long *get_array = to_long_Array(real_number, n);
        long result = largest_production(get_array, k, n);
        printf("%ld\n", result);
    }
    return 0;
}

long *to_long_Array(char *numberString, long n) {
    long *numberArray = malloc(n * sizeof(long));

    for (long i = 0; i < n; i++) {

        numberArray[i] = numberString[i] - '0';

    }

    return numberArray;
}


long largest_production(long *array, long number_of_conscutive, long n) {

    long maxMultiplication = 0;
    for (long i = 0; i < (n - number_of_conscutive) + 1; i++) {

        long product = 1;

        for (long j = i; j < (number_of_conscutive + i); j++) {
            product *= array[j];
        }

        maxMultiplication = (maxMultiplication > product ? maxMultiplication : product);
    }

    return maxMultiplication;
}
