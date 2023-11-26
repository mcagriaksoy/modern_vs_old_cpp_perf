// Mehmet Cagri Aksoy - 2023

// To see the performance difference between count up to SIZE and count down to zero loops
// Please run the compiler without any optimization flags! -O0
// g++ -O0 gpp_loop_countUp_vs_countDown.cpp -o gpp_loop_countUp_vs_countDown
// Otherwise, you will see the same performance for both loops or even count up loop will be faster.
// gpp_loop_countUp_vs_countDown.cpp

#include <iostream>

#define NUMBER_OF_TESTS 100
#define SIZE 9000000

using namespace std;

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
        time_taken += (double(end - start) / double(CLOCKS_PER_SEC));
    }
    time_taken /= NUMBER_OF_TESTS;
    cout << "Average time consumption \"Count Up to SIZE\" loop: " << time_taken << " seconds" << endl;

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
        time_taken2 += double(end - start) / double(CLOCKS_PER_SEC);
    }
    time_taken2 /= NUMBER_OF_TESTS;
    cout << "Average time consumption \"Count Down to Zero\" loop: " << time_taken2 << " seconds" << endl;
    // Comparison
    if (time_taken2 > time_taken)
    {
        cout << "Count Up to SIZE loop is " << time_taken2 / time_taken << " times faster than Count Down to Zero" << endl;
        cout << "Count Up to SIZE loop is " << time_taken2 - time_taken << " seconds faster than Count Down to Zero" << endl;
        cout << "Performance difference percentage: " << (time_taken2 - time_taken) / time_taken2 * 100 << "%" << endl;
    }
    else
    {
        cout << "Count Down to Zero loop is " << time_taken / time_taken2 << " times faster than Count Up to SIZE" << endl;
        cout << "Count Down to Zero loop is " << time_taken - time_taken2 << " seconds faster than Count Up to SIZE" << endl;
        cout << "Performance difference percentage: " << (time_taken - time_taken2) / time_taken * 100 << "%" << endl;
    }
}