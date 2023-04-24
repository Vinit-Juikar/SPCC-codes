#include <iostream>
int compute(int a, int b, int c, int d)
{
    int x = a + b;
    int y = c + d;
    int z = x * y;
    return z;
}
int optimized_compute(int a, int b, int c, int d)
{
    int x = a + b;
    int y = c + d;
    int z = x * y;
    return z;
}
int main()
{
    int a = 2, b = 3, c = 4, d = 5;

    // Original computation
    int z1 = compute(a, b, c, d);
    std::cout << "Original computation result: " << z1 << std::endl;

    // Optimized computation
    int z2 = optimized_compute(a, b, c, d);
    std::cout << "Optimized computation result: " << z2 << std::endl;

    return 0;
}
