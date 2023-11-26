// Mehmet Cagri Aksoy

/**
 * @brief Compares the performance of std::iota and manual assignment in a single-core environment.
 *
 * This program measures the average time consumption of std::iota and manual assignment loops.
 * It performs multiple tests and calculates the average time taken for each loop.
 * The program then compares the performance of the two loops and prints the results.
 *
 * @return int The exit status of the program.
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

#define NUMBER_OF_TESTS 150
#define SIZE 2000000

// manuel assign vs std:iota single core performance test
int main()
{
    vector<int> v(SIZE);

    clock_t start;
    clock_t end;
    double time_taken = 0;
    int test_number = NUMBER_OF_TESTS;

    // TEST 1
    while (test_number--)
    {
        start = clock();
        iota(v.begin(), v.end(), 0);
        end = clock();
        time_taken += (double(end - start) / double(CLOCKS_PER_SEC));
    }
    time_taken /= NUMBER_OF_TESTS;
    cout << "Average time consumption \"std:iota\" loop: " << time_taken << " seconds" << endl;

    // TEST 2
    vector<int> v2(SIZE);
    double time_taken2 = 0;
    test_number = NUMBER_OF_TESTS;
    while (test_number--)
    {
        start = clock();
        for (int i = 0; i < SIZE; i++)
        {
            v2.at(i) = i;
        }
        end = clock();
        time_taken2 += double(end - start) / double(CLOCKS_PER_SEC);
    }
    time_taken2 /= NUMBER_OF_TESTS;
    cout << "Average time consumption \"manuel assign\" loop: " << time_taken2 << " seconds" << endl;
    // Comparison
    if (time_taken2 > time_taken)
    {
        cout << "std:iota loop is " << time_taken2 / time_taken << " times faster than manuel assign" << endl;
        cout << "std:iota loop is " << time_taken2 - time_taken << " seconds faster than manuel assign" << endl;
        cout << "Performance difference percentage: " << (time_taken2 - time_taken) / time_taken2 * 100 << "%" << endl;
    }
    else
    {
        cout << "manuel assign loop is " << time_taken / time_taken2 << " times faster than std:iota" << endl;
        cout << "manuel assign loop is " << time_taken - time_taken2 << " seconds faster than std:iota" << endl;
        cout << "Performance difference percentage: " << (time_taken - time_taken2) / time_taken * 100 << "%" << endl;
    }
}