#include <iostream>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define MAX_ABS(a, b) MAX(ABS(a), ABS(b))

int main()
{
    int x = -5;
    int y = 10;
    std::cout << "The maximum absolute value of " << x << " and " << y << " is " << MAX_ABS(x, y) << std::endl;

    return 0;
}
