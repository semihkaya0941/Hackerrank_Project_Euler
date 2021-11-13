
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


long long int square_in_order(int number) ;
long long int square_the_sum(int number);
long long int absolute (long long int result);

int main() {
    int test_case;
    scanf("%d", &test_case);
    int arr[test_case];
    int n;

    for (int a0 = 0; a0 < test_case; a0++) {

        scanf("%d", &n);
        arr[a0] = n ;
    }

    for (int j = 0; j < test_case; j++) {
        long long int result =   llabs((square_in_order(arr[j]) - square_the_sum(arr[j])));
        printf("%lld\n", result);

    }

    return 0;
}

long long int square_the_sum(int number) {
    long long int sum2 = 0;
    for (int i = 1; i <= number; i++) {
        sum2 += i;
    }

    return sum2*sum2;
}

long long int square_in_order(int number) {

    long long int sum1 = 0;
    for (int i = 1; i <= number; i++) {

        sum1 += i * i;
    }

    return sum1;
}

long long int absolute (long long int result){

    if (result < 0){
        result *= -1 ;
    }
    return result;
}
