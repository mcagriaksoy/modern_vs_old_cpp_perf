// Mehmet Cagri Aksoy

#include <algorithm>
#include <iostream>

using namespace std;

#define NUMBER_OF_TESTS 150
#define SIZE 2000000

// manuel assign vs std:fill single core performance test
int main()
{
    vector<string> v(SIZE);

    clock_t start;
    clock_t end;
    double time_taken = 0;
    int test_number = NUMBER_OF_TESTS;

    // TEST 1
    while (test_number--)
    {
        start = clock();
        fill(v.begin(), v.end(), "a");
        end = clock();
        time_taken += (double(end - start) / double(CLOCKS_PER_SEC));
    }
    time_taken /= NUMBER_OF_TESTS;
    cout << "Average time consumption \"std:fill\" loop: " << time_taken << " seconds" << endl;

    // TEST 2
    vector<string> v2(SIZE);
    double time_taken2 = 0;
    test_number = NUMBER_OF_TESTS;
    while (test_number--)
    {
        start = clock();
        for (int i = 0; i < SIZE; i++)
        {
            v2.at(i) = "a";
        }
        end = clock();
        time_taken2 += double(end - start) / double(CLOCKS_PER_SEC);
    }
    time_taken2 /= NUMBER_OF_TESTS;
    cout << "Average time consumption \"manuel assign\" loop: " << time_taken2 << " seconds" << endl;
    // Comparison
    if (time_taken2 > time_taken)
    {
        cout << "std:fill loop is " << time_taken2 / time_taken << " times faster than manuel assign" << endl;
        cout << "std:fill loop is " << time_taken2 - time_taken << " seconds faster than manuel assign" << endl;
        cout << "Performance difference percentage: " << (time_taken2 - time_taken) / time_taken2 * 100 << "%" << endl;
    }
    else
    {
        cout << "manuel assign loop is " << time_taken / time_taken2 << " times faster than std:fill" << endl;
        cout << "manuel assign loop is " << time_taken - time_taken2 << " seconds faster than std:fill" << endl;
        cout << "Performance difference percentage: " << (time_taken - time_taken2) / time_taken * 100 << "%" << endl;
    }
}