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

int product(int rows, int cols, int array[rows][cols]);

int find_max_product(int res , int num1, int num2, int num3, int num4);

int main() {
    int grid[20][20];
    for (int grid_i = 0; grid_i < 20; grid_i++) {
        for (int grid_j = 0; grid_j < 20; grid_j++) {

            scanf("%d", &grid[grid_i][grid_j]);
        }
    }
    int final_result = product(20, 20, grid);

    printf("%d", final_result);
    return 0;
}


int product(int rows, int cols, int array[rows][cols]) {
    int horizontal_product = 0, updown_product = 0, right_diagonal_product = 0, left_diagonal_product = 0;
    int result = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {


            if (j < 17) {
                horizontal_product = array[i][j] * array[i][j + 1] * array[i][j + 2] * array[i][j + 3];
            }

            if (i < 17) {
                updown_product = array[i][j] * array[i + 1][j] * array[i + 2][j] * array[i + 3][j];
            }
            if (i < 17 && j < 17) {
                right_diagonal_product = array[i][j] * array[i + 1][j + 1] * array[i + 2][j + 2] * array[i + 3][j + 3];
                left_diagonal_product =
                        array[i][19 - j] * array[i + 1][18 - j] * array[i + 2][17 - j] * array[i + 3][16 - j];
            }


             result = find_max_product(result,horizontal_product, updown_product, right_diagonal_product,
                                          left_diagonal_product);
        }
    }

    return result;
}

int find_max_product(int res , int num1, int num2, int num3, int num4) {


    int max_ab, max_cd, max_num;
    max_ab = num1 > num2 ? num1 : num2;
    max_cd = num3 > num4 ? num3 : num4;
    max_num = max_ab > max_cd ? max_ab : max_cd;



    return max_num > res ? max_num : res;

}




