// Creator: Mehmet Cagri Aksoy
// Result: Prefix is faster than postfix!
// Whether you use compiler optimizations or not, prefix is always faster than postfix.
#include <iostream>

#define NUMBER_OF_TESTS 1199939

using namespace std;

void test1()
{
    double i = 0;
    time_t start;
    time_t end;
    // Postfix test
    start = clock();
    while (i < NUMBER_OF_TESTS)
    {
        i++;
    }
    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Postfix operation took " << fixed << time_taken << " seconds" << endl;

    i = 0;
    // Prefix test
    start = clock();
    while (i < NUMBER_OF_TESTS)
    {
        ++i;
    }
    end = clock();
    double time_taken2 = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Prefix  operation took " << fixed << time_taken2 << " seconds" << endl;

    if (time_taken > time_taken2)
    {
        cout << "Postfix is slower than prefix " << time_taken / time_taken2 << " times" << endl;
        cout << "Postfix is slower " << time_taken - time_taken2 << " seconds" << endl;
    }
    else
    {
        cout << "Prefix is slower than postfix " << time_taken2 / time_taken << " times" << endl;
        cout << "Prefix is slower " << time_taken2 - time_taken << " seconds" << endl;
    }
}

void test2()
{
    cout << "Enter the number of tests: ";
    int number_of_tests = 0;
    cin >> number_of_tests;
    cout << endl;

    double i = 0;
    time_t start;
    time_t end;
    // Postfix test
    start = clock();
    while (i < number_of_tests)
    {
        i++;
    }
    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Postfix operation took " << fixed << time_taken << " seconds" << endl;

    i = 0;
    // Prefix test
    start = clock();
    while (i < number_of_tests)
    {
        ++i;
    }
    end = clock();
    double time_taken2 = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Prefix  operation took " << fixed << time_taken2 << " seconds" << endl;

    if (time_taken > time_taken2)
    {
        cout << "Postfix is slower than prefix " << time_taken / time_taken2 << " times" << endl;
        cout << "Postfix is slower " << time_taken - time_taken2 << " seconds" << endl;
    }
    else
    {
        cout << "Prefix is slower than postfix " << time_taken2 / time_taken << " times" << endl;
        cout << "Prefix is slower " << time_taken2 - time_taken << " seconds" << endl;
    }
}

int main()
{
    // With pre-defined test size case
    test1();

    // With user input test size case
    test2();

    return 0;
}