#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

bool check_palindrome(int generated_n);
int largest_palindrome(int input_n);

int main()
{
    int test_number, answer;
    scanf("%d", &test_number);
    if (test_number >= 1 && test_number <= 100)
    {
        for (int a0 = 0; a0 < test_number; a0++)
        {
            int input_n;
            scanf("%d", &input_n);

            if (input_n > 101101 && input_n < 1000000)
            {
                answer = largest_palindrome(input_n);
                printf("%d", answer);
                printf("\n");
            }
        }
    }
    return 0;
}

bool check_palindrome(int generated_n)
{

    int temp = 0, restore = generated_n;

    while (generated_n > 0)
    {
        temp = temp * 10 + (generated_n % 10);
        generated_n = floor(generated_n / 10);
    }

    if (temp == restore)
        return true;

    return false;
}

int largest_palindrome(int input_n)
{

    int largest;

    for (int i = 100; i <= 999; i++)
    {
        for (int j = 100; j <= 999; j++)
        {
            int generated_n = i * j;

            if (check_palindrome(generated_n) && generated_n < input_n && generated_n > largest )
            {
                    largest = generated_n;
            }
        }
    }

    return largest;
}