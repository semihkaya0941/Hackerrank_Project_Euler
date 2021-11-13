//
// Created by semih on 11/6/2021.
// Purpose : Project Euler #12: Highly divisible triangular number

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int find_triangular_numbers(int number_of_divisors);

int divisors_of_a_triangular_number(int triangle_number);

int main() {
    int test_case;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d", &test_case);
    int input;
    for (int i = 1; i <=test_case; i++) {
        scanf("%d", &input);
        int final_number = find_triangular_numbers(input);
        printf("%d\n", final_number);
    }


    return 0;
}

int find_triangular_numbers(int number_of_divisors) {
    int n = 1;
    int triangle_number, new_number_of_divisors = 0;

    while (number_of_divisors >= new_number_of_divisors) {
        triangle_number = n * (n + 1) / 2;
        new_number_of_divisors = divisors_of_a_triangular_number(triangle_number);
        n++;
    }

    return triangle_number;//4 ,980,992,975,990
    //  [1,3,6,10,15,21,28,...,675] 0.3, 4 * 0.3 = 1.2 = 0.3ms + 0.01
//      [1,2,4,4,4,4,6,10,14,123,...,992] // trıangles dıvısors
}

int divisors_of_a_triangular_number(int triangle_number) {

    int new_divisors = 0;
    for (int i = 1; i <= sqrt(triangle_number) ; i++) {

        if (triangle_number % i == 0) {
            new_divisors += 2;
        }
    }

    if ( (int)sqrt(triangle_number) * (int)sqrt(triangle_number) == triangle_number) {
        new_divisors -= 1;
    }

    return new_divisors;
}
