// Creator: Mehmet Cagri Aksoy

/**
 * @brief Compares the performance of a C array and a vector in a single-core performance test.
 *
 * This program measures the time taken to increment each element of a C array and a vector using a loop.
 * It performs the test multiple times and calculates the average time consumption for each loop.
 * Finally, it compares the performance of the C array and the vector and prints the results.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define NUMBER_OF_TESTS 150
#define SIZE 2000000

// vector vs c array single core performance test
int main()
{
    vector<int> v(SIZE);
    int c_arr[SIZE];

    clock_t start;
    clock_t end;
    double time_taken = 0;
    int test_number = NUMBER_OF_TESTS;

    // TEST 1
    while (test_number--)
    {
        start = clock();
        for (int i = 0; i < SIZE; i++)
        {
            c_arr[i]++;
        }
        end = clock();
        time_taken += (double(end - start) / double(CLOCKS_PER_SEC));
    }
    time_taken /= NUMBER_OF_TESTS;
    cout << "Average time consumption \"C array\" loop: " << time_taken << " seconds" << endl;

    // TEST 2
    double time_taken2 = 0;
    test_number = NUMBER_OF_TESTS;
    while (test_number--)
    {
        start = clock();
        for (auto &e : v)
        {
            e++;
        }
        end = clock();
        time_taken2 += double(end - start) / double(CLOCKS_PER_SEC);
    }
    time_taken2 /= NUMBER_OF_TESTS;
    cout << "Average time consumption \"vector\" loop: " << time_taken2 << " seconds" << endl;
    // Comparison
    if (time_taken2 > time_taken)
    {
        cout << "C array loop is " << time_taken2 / time_taken << " times faster than vector" << endl;
        cout << "C array loop is " << time_taken2 - time_taken << " seconds faster than vector" << endl;
        cout << "Performance difference percentage: " << (time_taken2 - time_taken) / time_taken2 * 100 << "%" << endl;
    }
    else
    {
        cout << "vector loop is " << time_taken / time_taken2 << " times faster than C array" << endl;
        cout << "vector loop is " << time_taken - time_taken2 << " seconds faster than C array" << endl;
        cout << "Performance difference percentage: " << (time_taken - time_taken2) / time_taken * 100 << "%" << endl;
    }
}