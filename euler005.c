
#include <stdio.h>


int result_function(int variable);

int greatest_common_divisor(int number1, int number2);

int main() {
    int t;
    scanf("%d", &t);
    for (int a0 = 0; a0 < t; a0++) {
        int n;
        scanf("%d", &n);

        int result = result_function(n);

        printf("%d\n", result);
    }
    return 0;
}


int result_function(int variable) {

    int result = 6;
    if (variable <= 2) {
        return variable;
    }
    if (variable == 3) {
        return 6;
    }
    for (int i = 4; i <= variable; i++) {
        result *= i / greatest_common_divisor(result, i);
    }

    return result;
}

int greatest_common_divisor(int number1, int number2) {

    while (number1 != number2) {
        if (number1 > number2)
            number1 -= number2;
        else
            number2 -= number1;
    }
    return number1;
}
