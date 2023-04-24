// recursive macros

#include <iostream>

using namespace std;

// define function to implement macro
int macro(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return macro(n - 1) + macro(n - 2);
    }
}

int main()
{
    // define macro
    int fib = macro(10);

    // print macro value
    cout << "Fibonacci number: " << fib << endl;

    return 0;
}
