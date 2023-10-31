// Mehmet Cagri Aksoy

#include <algorithm>
#include <iostream>

using namespace std;

#define NUMBER_OF_TESTS 150
#define SIZE 900000

// std::reverse vs std:swap single core performance test
int main()
{
    vector<string> v(SIZE);
    fill(v.begin(), v.end(), "abc");

    clock_t start;
    clock_t end;
    double time_taken = 0;
    int test_number = NUMBER_OF_TESTS;

    // TEST 1
    while (test_number--)
    {
        start = clock();
        for (int i = 0; i <= (SIZE / 2) - 1; i++)
        {
            swap(v.at(i), v.at(SIZE - i - 1));
        }
        end = clock();
        time_taken += (double(end - start) / double(CLOCKS_PER_SEC));
    }
    time_taken /= NUMBER_OF_TESTS;
    cout << "Average time consumption \"std:swap\" loop: " << time_taken << " seconds" << endl;

    // TEST 2
    vector<string> v2(SIZE);
    double time_taken2 = 0;
    test_number = NUMBER_OF_TESTS;
    while (test_number--)
    {
        start = clock();
        reverse(v2.begin(), v2.end());
        end = clock();
        time_taken2 += double(end - start) / double(CLOCKS_PER_SEC);
    }
    time_taken2 /= NUMBER_OF_TESTS;
    cout << "Average time consumption \"std::reverse\" loop: " << time_taken2 << " seconds" << endl;
    // Comparison
    if (time_taken2 > time_taken)
    {
        cout << "std:swap loop is " << time_taken2 / time_taken << " times faster than std::reverse" << endl;
        cout << "std:swap loop is " << time_taken2 - time_taken << " seconds faster than std::reverse" << endl;
        cout << "Performance difference percentage: " << (time_taken2 - time_taken) / time_taken2 * 100 << "%" << endl;
    }
    else
    {
        cout << "std::reverse loop is " << time_taken / time_taken2 << " times faster than std:swap" << endl;
        cout << "std::reverse loop is " << time_taken - time_taken2 << " seconds faster than std:swap" << endl;
        cout << "Performance difference percentage: " << (time_taken - time_taken2) / time_taken * 100 << "%" << endl;
    }
}