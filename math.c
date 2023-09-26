#include <math.h>

int is_prime(unsigned long long value)
{
    
    for (int i = 2; i * i <= value; i++)
    {
        if (value % i == 0)
            return 0;
    }
    return 1;

}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
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
