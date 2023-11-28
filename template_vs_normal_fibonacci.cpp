// Creator: Mehmet Cagri Aksoy
// The difference is that this snippet uses template fibonacci implementation instead of normal fibonacci implementation.
// I have used constexpr keyword to make the compiler calculate the fibonacci values at compile time. Which introduces c++17. If you have an older compiler, you can use the compiler flag -std=c++17 to compile this code.

// Summary:
// with or without compiler optimizations, template fibonacci implementation is faster than normal fibonacci implementation!

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define NUMBER_OF_TESTS 100
#define FIBONACCI_NUMBER 30

int fibonacci_normal(int n)
{
    if (n > 1)
    {
        return fibonacci_normal(n - 1) + fibonacci_normal(n - 2);
    }

    return n;
}

template <int N>
int fibonacci_template()
{
    if constexpr (N > 1)
    {
        return fibonacci_template<N - 1>() + fibonacci_template<N - 2>();
    }

    return N;
}

// fibonacci template vs normal fibonacci implementation performance test
int main()
{
    clock_t start;
    clock_t end;
    double time_taken = 0;
    int test_number = NUMBER_OF_TESTS;
    while (test_number--)
    {
        start = clock();
        fibonacci_normal(FIBONACCI_NUMBER);
        end = clock();
        time_taken += (double(end - start) / double(CLOCKS_PER_SEC));
    }
    time_taken /= NUMBER_OF_TESTS;

    cout << "Average time consumption \"normal\" fibonacci: " << time_taken << " seconds" << endl;

    test_number = NUMBER_OF_TESTS;
    double time_taken2 = 0;

    while (test_number--)
    {
        start = clock();
        fibonacci_template<FIBONACCI_NUMBER>();
        end = clock();
        time_taken2 += (double(end - start) / double(CLOCKS_PER_SEC));
    }
    time_taken2 /= NUMBER_OF_TESTS;

    cout << "Average time consumption \"template\" fibonacci: " << time_taken2 << " seconds" << endl;

    if (time_taken2 < time_taken)
    {
        cout << "Template fibonacci is " << time_taken / time_taken2 << " times faster than normal" << endl;
        cout << "Template fibonacci is " << time_taken - time_taken2 << " seconds faster than normal" << endl;
        cout << "Performance difference percentage: " << (time_taken - time_taken2) / time_taken * 100 << "%" << endl;
    }
    else
    {
        cout << "Normal fibonacci is " << time_taken2 / time_taken << " times faster than template" << endl;
        cout << "Normal fibonacci is " << time_taken2 - time_taken << " seconds faster than template" << endl;
        cout << "Performance difference percentage: " << (time_taken2 - time_taken) / time_taken2 * 100 << "%" << endl;
    }
}