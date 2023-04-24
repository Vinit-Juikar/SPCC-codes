// parameterized macros

#include <iostream>

#define SQUARE(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))

int main()
{
    int a = 5;
    std::cout << "Square of " << a << " is " << SQUARE(a) << std::endl;
    std::cout << "Cube of " << a << " is " << CUBE(a) << std::endl;

    // parameterized macros
#define POWER(x, n)                   \
    ({                                \
        int result = 1;               \
        for (int i = 0; i < (n); i++) \
        {                             \
            result *= (x);            \
        }                             \
        result;                       \
    })

    int b = 2;
    int c = 3;
    std::cout << b << " to the power of " << c << " is " << POWER(b, c) << std::endl;

    return 0;
}
