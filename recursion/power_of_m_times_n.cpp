#include <iostream>
#include <chrono>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

unsigned long long power_recursion(unsigned long long m, unsigned long long n)
{
    if (n == 0)
        return 1;

    return m * power_recursion(m, n - 1);
}

unsigned long long power_recursion_optimized(unsigned long long m, unsigned long long n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return power_recursion_optimized(m, n / 2) * power_recursion_optimized(m, n / 2);

    return m * power_recursion_optimized(m, n / 2) * power_recursion_optimized(m, n / 2);
}

unsigned long long power_recursion_optimized_v2(unsigned long long m, unsigned long long n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return power_recursion_optimized_v2(m * m, n / 2);

    return m * power_recursion_optimized_v2(m * m, (n - 1) / 2);
}

unsigned long long power_recursion_optimized_v3(unsigned long long m, unsigned long long n)
{
    unsigned long long temp;

    if (n == 0)
        return 1;

    temp = power_recursion_optimized_v3(m, n / 2);

    if (n % 2 == 0)
        return temp * temp;

    return m * temp * temp;
}

int main()
{
    auto start1 = high_resolution_clock::now();
    cout << power_recursion(2, 60) << endl;
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    auto start2 = high_resolution_clock::now();
    cout << power_recursion_optimized(2, 60) << endl;
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    auto start3 = high_resolution_clock::now();
    cout << power_recursion_optimized_v2(2, 60) << endl;
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);

    auto start4 = high_resolution_clock::now();
    cout << power_recursion_optimized_v3(2, 60) << endl;
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(stop4 - start4);

    auto start5 = high_resolution_clock::now();
    cout << pow(2, 60) << endl;
    auto stop5 = high_resolution_clock::now();
    auto duration5 = duration_cast<microseconds>(stop5 - start5);

    cout << "Time taken by Normal Recursion: "
         << duration1.count() << " microseconds" << endl;

    cout << "Time taken by Opt Recursion: "
         << duration2.count() << " microseconds" << endl;

    cout << "Time taken by Opt Recursion V2: "
         << duration3.count() << " microseconds" << endl;

    cout << "Time taken by Opt Recursion V3: "
         << duration4.count() << " microseconds" << endl;

    cout << "Time taken by Inbuilt: "
         << duration5.count() << " microseconds" << endl;

    return 0;
}