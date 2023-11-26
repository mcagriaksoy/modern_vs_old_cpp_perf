// Mehmet Cagri Aksoy

/**
 * @brief Compares the performance of range-based loop and std::transform loop on a vector of integers.
 *
 * This program measures the average time consumption of both range-based loop and std::transform loop
 * for a given number of tests. It then compares the performance of the two loops and prints the results.
 *
 * @return int The exit status of the program.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define NUMBER_OF_TESTS 100
#define SIZE 1000000

// Range based loop vs std:transform loop single core performance test
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
        transform(v.begin(), v.end(), v.begin(), [](int i)
                  { return i + 1; });
        end = clock();
        time_taken += (double(end - start) / double(CLOCKS_PER_SEC));
    }
    time_taken /= NUMBER_OF_TESTS;
    cout << "Average time consumption \"std:transform\" loop: " << time_taken << " seconds" << endl;

    // TEST 2
    vector<int> v2(SIZE);
    double time_taken2 = 0;
    test_number = NUMBER_OF_TESTS;
    while (test_number--)
    {
        start = clock();
        for (auto &e : v2)
        {
            ++e;
        }
        end = clock();
        time_taken2 += double(end - start) / double(CLOCKS_PER_SEC);
    }
    time_taken2 /= NUMBER_OF_TESTS;
    cout << "Average time consumption \"Range based loop\" loop: " << time_taken2 << " seconds" << endl;
    // Comparison
    if (time_taken2 > time_taken)
    {
        cout << "std:transform loop is " << time_taken2 / time_taken << " times faster than Range based loop" << endl;
        cout << "std:transform loop is " << time_taken2 - time_taken << " seconds faster than Range based loop" << endl;
        cout << "Performance difference percentage: " << (time_taken2 - time_taken) / time_taken2 * 100 << "%" << endl;
    }
    else
    {
        cout << "Range based loop loop is " << time_taken / time_taken2 << " times faster than std:transform" << endl;
        cout << "Range based loop loop is " << time_taken - time_taken2 << " seconds faster than std:transform" << endl;
        cout << "Performance difference percentage: " << (time_taken - time_taken2) / time_taken * 100 << "%" << endl;
    }
}