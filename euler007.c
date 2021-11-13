//
// Created by semih on 8/31/2021.
//

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int is_prime(int n);

void prime_number_order(int test_case);

int get_large_number(int test_case, int input_arr[]);


int *get_prime_array(int length);

int main() {


    int test_case;


    scanf("%d", &test_case);
    prime_number_order(test_case);


    return 0;
}

void prime_number_order(int test_case) {

    int th_number;
    int input_arr[test_case]; // input_Arr = [3,6]
    for (int i = 0; i < test_case; i++) {
        scanf("%d", &th_number);

        input_arr[i] = th_number;
    }
    int large_number = get_large_number(test_case, input_arr);

    int *order_prime_number = get_prime_array(large_number); // order_prime_number = [ 2 3 5 7 11 13]

    for (int k = 0; k < test_case ; k++) {

            printf("%d\n", order_prime_number[input_arr[k]-1]  );

    }
}

int *get_prime_array(int length) {

    int * prime_array;
    prime_array = (int*)malloc(length * sizeof(int));
    int j = 3 ;
    int counter = 1;
    prime_array[0] = 2;
    while (length != counter) {

        if (is_prime(j)) {
            prime_array[counter++] = j ;
        }

        j += 2;

    }
    return prime_array;
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


int is_prime(int n) {
    for (int i = 3; i <= sqrt(n); i += 2) {

        if (n % i == 0) {
            return 0;
        }

    }

    return 1;
}
