#include <stdio.h>

long long sum(long long a, long long b, long long c)
{
    return a + b + c;
}

int main()
{
    long long x = sum(1, 2, 3);
    long long y = sum(5, 4, 3);

    printf("%lld, %lld\n", x, y);
    return 0;
}