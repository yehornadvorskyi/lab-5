// Compiler: MSVC (Microsoft Visual Studio 2022), Standard: C++20, x64, Release configuration
// обчислення: A, B, C1, C2, D1, D2, F
// повільні A і B
// залежності: B(A), C1(B), D1(C1, C2), F(D1, D2)

#include <chrono>
#include <future>
#include <iostream>
#include <string>
#include <syncstream>
#include <thread>

using namespace std;

// отут повільне обчислення
void slow(const string& name)
{
    this_thread::sleep_for(chrono::seconds(7));
    osyncstream(cout) << name << endl;
}

// отут швидке
void quick(const string& name)
{
    this_thread::sleep_for(chrono::seconds(1));
    osyncstream(cout) << name << endl;
}

void secondThread()
{
    quick("C2");
    quick("D2");
}

void work()
{
    auto start = chrono::steady_clock::now();

    
    future<void> second = async(launch::async, secondThread);

    
    slow("A");
    slow("B");
    quick("C1");

   
    second.get();

    quick("D1");
    quick("F");

    auto end = chrono::steady_clock::now();
    chrono::duration<double> time = end - start;
    osyncstream(cout) << "Time: " << time.count() << " seconds" << endl;
    osyncstream(cout) << "Work is done!" << endl;
}

int main()
{
    work();
}
