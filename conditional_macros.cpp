// conditional macros

#include <iostream>
#define PI 3.14159
#define SQUARE(x) ((x) * (x))
#define DEBUG 1
int main()
{
    double radius = 2.5;
    double area = PI * SQUARE(radius);
#if DEBUG
    std::cout << "The area of a circle with radius " << radius << " is " << area << std::endl;
#endif
#ifndef DEBUG
    std::cout << area << std::endl;
#endif
    return 0;
}
