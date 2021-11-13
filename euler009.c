//
// Created by semih on 9/21/2021.
//

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long long int find_the_pythagorean_triple(int n);

int get_b(int sum, int i);

int main() {
    int t;


    scanf("%d", &t);
    for (int a0 = 1; a0 <= t; a0++) {
        int n;

        scanf("%d", &n);
        if (n >= 1 && n <= 3000) {
            long long int final_result = find_the_pythagorean_triple(n);
            printf("%lld\n", final_result);
        }
    }
    return 0;
}

long long int find_the_pythagorean_triple(int sum) {

    long long int max_result = -1;



    for (int i = 1; i <= ceil(sum / 3 ); i++) {
        int j = get_b(sum, i);
        if (j == -1) {
            continue;
        }
        int k = sum - i - j;
        if (i < j && j < k) {
            if ((i * i) + (j * j) == (k * k)) {
                long long int result = i * j * k;
                if(result > max_result){
                    max_result = result ;
                }


            }
        }
    }

    return max_result;


}

int get_b(int sum, int i) {
    if (sum == i) {
        return -1;
    }
    int b = (sum * sum - 2 * i * sum) / (2 * sum - 2 * i);
    return b;
}

