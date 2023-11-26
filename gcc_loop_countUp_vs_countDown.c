// Mehmet Cagri Aksoy - 2023

#include "stdio.h"
#include <time.h>

#define NUMBER_OF_TESTS 100
#define SIZE 9000000

int main()
{
    clock_t start;
    clock_t end;
    double time_taken = 0;
    int test_number = NUMBER_OF_TESTS;
    int sum = 0;

    // TEST 1
    while (test_number--)
    {
        start = clock();
        for (int i = 0; i < SIZE; i++)
        {
            sum += i;
        }
        end = clock();
        time_taken += ((double)(end - start) / (double)(CLOCKS_PER_SEC));
    }
    time_taken /= NUMBER_OF_TESTS;
    printf("Average time consumption \"Count Up to SIZE\" loop: %f seconds\n", time_taken);

    // TEST 2
    double time_taken2 = 0;
    test_number = NUMBER_OF_TESTS;
    while (test_number--)
    {
        start = clock();
        for (int i = SIZE; i > 0; i--)
        {
            sum += i;
        }
        end = clock();
        time_taken2 += ((double)(end - start) / (double)(CLOCKS_PER_SEC)); // Move this line inside the loop
    }
    time_taken2 /= NUMBER_OF_TESTS;
    printf("Average time consumption \"Count Down to Zero\" loop: %f seconds\n", time_taken2);

    if (time_taken2 > time_taken)
    {
        printf("Count Up to SIZE loop is %f times faster than Count Down to Zero\n", time_taken2 / time_taken);
        printf("Count Up to SIZE loop is %f seconds faster than Count Down to Zero\n", time_taken2 - time_taken);
        printf("Performance difference percentage: %f", (time_taken2 - time_taken) / time_taken2 * 100);
    }
    else
    {
        printf("Count Down to Zero loop is  %f times faster than Count Up to SIZE\n", time_taken / time_taken2);
        printf("Count Down to Zero loop is  %f seconds faster than Count Up to SIZE\n", time_taken - time_taken2);
        printf("Performance difference percentage: %f \n", (time_taken - time_taken2) / time_taken * 100);
    }
}