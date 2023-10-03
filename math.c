#include <math.h>
#include "math.h"

int is_prime(unsigned long long value)
{
	unsigned long long rt = (unsigned long long)sqrt(value);
	if (value == 2 || value == 3)
		return 1;
	if (value < 2 || value % 2 == 0 || value % 3 == 0)
		return 0;
    for (unsigned long long i = 5; i <= rt; i += 6)
    {
        if (value % i == 0 || value % (i + 2) == 0)
            return 0;
    }
    return 1;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd (b, a % b);
}

int binpow(int a, int n) 
{
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow(a, n - 1) * a;
	else
    {
		int b = binpow(a, n / 2);
		return b * b;
	}
}

int gray(int n) 
{
	return n ^ (n >> 1);
}
