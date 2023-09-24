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


// mind storm
// process
// seed /// why ?
