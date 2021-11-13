//
// Created by semih on 10/16/2021.
//
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void prime_number_order(int test_case);

int get_large_number(int test_case, int input_arr[]);

int get_prime_array(int *new_array, int length);

int is_prime(int n);

int sum_elements_of_arr(int *prime_number_array, int largest_number, int new_length);

int main() {

    int test_case;
    scanf("%d", &test_case);
    prime_number_order(test_case);


    return 0;
}

void prime_number_order(int test_case) {
    int input_arr[test_case]; // input_Arr = [5,10]
    int n;


    for (int i = 0; i < test_case; i++) {

        scanf("%d", &n);
        input_arr[i] = n;
    }
    int large_number = get_large_number(test_case, input_arr);
    int *prime_array = (int *) calloc(1, sizeof(int));
    int new_length = get_prime_array(prime_array, large_number);
    //int lar = sizeof(order_array) / sizeof(order_array[0]);


    for (int k = 0; k < test_case; k++) {

        int result = sum_elements_of_arr(prime_array, input_arr[k], new_length);
        printf("%d\n", result);

    }


}

int get_large_number(int test_case, int input_arr[]) {
    int max = input_arr[0];
    for (int j = 1; j < test_case; j++) {
        if (max < input_arr[j]) {
            max = input_arr[j];
        }
    }
    return max;
}

int get_prime_array(int *new_array, int length) {



    //int *new_array = (int *) calloc(1, sizeof(int));
    int j = 3;
    int counter = 1;
    new_array[0] = 2;
    while (length >= j) {

        if (is_prime(j)) {
            counter++;
            new_array = (int *) realloc(new_array, counter * sizeof(int));
            new_array[counter - 1] = j;
        }

        j += 2;

    }
    return counter;
}

int is_prime(int n) {
    for (int i = 3; i <= sqrt(n); i += 2) {

        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int sum_elements_of_arr(int *prime_number_array, int largest_number, int new_length) {

    int sum = 0;


    for (int i = 0; i < new_length; i++) {

        if (largest_number >= prime_number_array[i]) {

            sum += prime_number_array[i];
        }
        else
            break;
    }
    return sum;
}