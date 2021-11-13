#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long long int find_largest_prime(long long int number)
{
    long long int largest_prime;

    if (number % 2 == 0)
    {
        largest_prime = 2;
        while (number % 2 == 0)
        {
            number = number / 2;
        }
    }

    for (long long int i = 3; i <= sqrt(number); i += 2)
    {
        while (number % i == 0)
        {
            largest_prime = i;
            number = number / i;
        }
    }

    if (number > 2)
        largest_prime = number;



    return largest_prime;
}

int main()
{

    int test_case;
    long long int n;
    long long int largest_prime;

    scanf("%d", &test_case);

    for (int i = 0; i < test_case; i++)
    {
        scanf("%lld", &n);
        long long int result = find_largest_prime(n);
        printf("%lld ", result);
        printf("\n");
    }

    return 0;
}
