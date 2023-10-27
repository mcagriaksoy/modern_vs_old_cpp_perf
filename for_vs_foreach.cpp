// Creator: Mehmet Cagri Aksoy

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define NUMBER_OF_TESTS 100
#define VECTOR_SIZE 10000000

// for_each vs for loop single core performance test
int main()
{
    vector<int> v(VECTOR_SIZE);
    clock_t start;
    clock_t end;
    double time_taken = 0;
    int test_number = NUMBER_OF_TESTS;

    // TEST 1
    while (test_number--)
    {
        start = clock();
        for_each(std::begin(v), std::end(v), [](auto &e)
                 { e++; });
        end = clock();
        time_taken += (double(end - start) / double(CLOCKS_PER_SEC));
    }
    time_taken /= NUMBER_OF_TESTS;
    cout << "Average time consumption \"for_each\" loop: " << time_taken << " seconds" << endl;

    // TEST 2
    vector<int> v2(VECTOR_SIZE);
    double time_taken2 = 0;
    test_number = NUMBER_OF_TESTS;
    while (test_number--)
    {
        start = clock();
        for (auto &e : v2)
        {
            e++;
        }
        end = clock();
        time_taken2 += double(end - start) / double(CLOCKS_PER_SEC);
    }
    time_taken2 /= NUMBER_OF_TESTS;
    cout << "Average time consumption \"for\" loop: " << time_taken2 << " seconds" << endl;
    // Comparison
    if (time_taken2 > time_taken)
    {
        cout << "for_each loop is " << time_taken2 / time_taken << " times faster than for" << endl;
        cout << "for_each loop is " << time_taken2 - time_taken << " seconds faster than for" << endl;
        cout << "Performance difference percentage: " << (time_taken2 - time_taken) / time_taken2 * 100 << "%" << endl;
    }
    else
    {
        cout << "for loop is " << time_taken / time_taken2 << " times faster than for_each" << endl;
        cout << "for loop is " << time_taken - time_taken2 << " seconds faster than for_each" << endl;
        cout << "Performance difference percentage: " << (time_taken - time_taken2) / time_taken * 100 << "%" << endl;
    }
}